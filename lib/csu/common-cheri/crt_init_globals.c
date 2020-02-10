/*-
 * Copyright (c) 2014 Robert N. M. Watson
 * Copyright (c) 2017-2018 Alex Richardson
 * All rights reserved.
 *
 * This software was developed by SRI International and the University of
 * Cambridge Computer Laboratory under DARPA/AFRL contract (FA8750-10-C-0237)
 * ("CTSRD"), as part of the DARPA CRASH research programme.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */
#include <sys/cdefs.h>
#include <stdint.h>
#include <stdlib.h>

#define CHERI_INIT_GLOBALS_GDC_ONLY
#include <cheri_init_globals.h>

/*
 * Avoid adding an unnecessary crt_init_globals() export from crt1.o for a
 * function that the compiler will inline anyway:
 */
#ifndef DONT_EXPORT_CRT_INIT_GLOBALS
#define CRT_INIT_GLOBALS_STATIC
#else
#define CRT_INIT_GLOBALS_STATIC static __always_inline
#endif

#ifndef CRT_INIT_GLOBALS_GDC_ONLY
CRT_INIT_GLOBALS_STATIC void crt_init_globals(void) __hidden;
#endif
CRT_INIT_GLOBALS_STATIC void crt_init_globals_3(
    void *, const void *, const void *) __hidden;

__attribute__((weak)) extern int _DYNAMIC __no_subobject_bounds;

CRT_INIT_GLOBALS_STATIC void
crt_init_globals_3(void *data_cap, const void *code_cap, const void *rodata_cap)
{
#ifdef PCREL_SYMBOL_ADDRESSES_WORK
	void* _pcc_after_daddui = 0;
	int64_t _dynamic_pcrel = 0;
	/*
	 * We can't get the address of _DYNAMIC in the purecap ABI before globals
	 * are initialized so we need to use dla here. If _DYNAMIC exists
	 * then the runtime-linker will have done the __cap_relocs already
	 * so we should be processing them here. Furthermore it will also have
	 * enforced relro so we will probably crash when attempting to write
	 * const pointers that are initialized to global addresses.
	 *
	 * TODO: Maybe clang should provide a __builtin_symbol_address() that is
	 * always filled in a static link time...
	 */
	__asm__ volatile(".global _DYNAMIC\n\t"
	    /*
	     * XXXAR: For some reason the attribute weak above is ignored if we
	     * don't also include it in the inline assembly
	     */
	    ".weak _DYNAMIC\n\t"
	    "lui %0, %%pcrel_hi(_DYNAMIC - 8)\n\t"
	    "daddiu %0, %0, %%pcrel_lo(_DYNAMIC - 4)\n\t"
	    "cgetpcc %1\n\t"
	    : "+r"(_dynamic_pcrel), "+C"(_pcc_after_daddui));

	/*
	 * If the address of _DYNAMIC is non-zero then we are dynamically linked
	 * and RTLD will be responsible for processing the capability relocs
	 * FIXME: MIPS only has 32-bit pcrelative relocations so this overflows
	 * For now just assume that if the pcrel value is greater than INT_MAX
	 * the value of _DYNAMIC is zero
	 */
	if ((vaddr_t)_pcc_after_daddui + _dynamic_pcrel != 0 &&
	    labs(_dynamic_pcrel) <= (int64_t)INT32_MAX)
		return;
#else
	/*
	 * XXXAR: Since the MIPS %pcrel doesn't appear to work to get the value
	 * of _DYNAMIC without a text relocation I changed LLD to emit a symbol
	 * _HAS__DYNAMIC instead. This also has the advantage that it only needs
	 * a single instruction to load rather than the full dla/pcrel sequence.
	 */
	int64_t _has__DYNAMIC;
	__asm__ volatile("ori %0, $zero, %%lo(_HAS__DYNAMIC)\n\t"
			 : "+r"(_has__DYNAMIC));
	/* If we are dynamically linked, the runtime linker takes care of this */
	if (_has__DYNAMIC)
		return;
#endif
	/* Otherwise we need to initialize globals manually */
	cheri_init_globals_3(data_cap, code_cap, rodata_cap);
}

#ifndef CRT_INIT_GLOBALS_GDC_ONLY
CRT_INIT_GLOBALS_STATIC void
crt_init_globals(void)
{

	crt_init_globals_3(__builtin_cheri_global_data_get(),
	    __builtin_cheri_program_counter_get(),
	    __builtin_cheri_global_data_get());
}
#endif /* !CRT_INIT_GLOBALS_GDC_ONLY */

#ifndef POSITION_INDEPENDENT_STARTUP
/* This is __always_inline since it is called before globals have been set up */
static __always_inline void
do_crt_init_globals(const Elf_Phdr *phdr, long phnum)
{
	const Elf_Phdr *phlimit = phdr + phnum;
	Elf_Addr text_start = (Elf_Addr)-1l;
	Elf_Addr text_end = 0;
	Elf_Addr readonly_start = (Elf_Addr)-1l;
	Elf_Addr readonly_end = 0;
	Elf_Addr writable_start = (Elf_Addr)-1l;
	Elf_Addr writable_end = 0;

	bool have_rodata_segment = false;
	bool have_text_segment = false;
	bool have_data_segment = false;

	/* Attempt to bound the data capability to only the writable segment */
	for (const Elf_Phdr *ph = phdr; ph < phlimit; ph++) {
		if (ph->p_type != PT_LOAD && ph->p_type != PT_GNU_RELRO) {
			/* Static binaries should not have a PT_DYNAMIC phdr */
			if (ph->p_type == PT_DYNAMIC) {
				__builtin_trap();
				break;
			}
			continue;
		}
		/*
		 * We found a PT_LOAD or PT_GNU_RELRO phdr. PT_GNU_RELRO will
		 * be a subset of a matching PT_LOAD but we need to add the
		 * range from PT_GNU_RELRO to the constant capability since
		 * __cap_relocs could have some constants pointing to the relro
		 * section. The phdr for the matching PT_LOAD has PF_R|PF_W so
		 * it would not be added to the readonly if we didn't also
		 * parse PT_GNU_RELRO.
		 */
		Elf_Addr seg_start = ph->p_vaddr;
		Elf_Addr seg_end = seg_start + ph->p_memsz;
		if ((ph->p_flags & PF_X)) {
			/* text segment */
			have_text_segment = true;
			text_start = MIN(text_start, seg_start);
			text_end = MAX(text_end, seg_end);
		} else if ((ph->p_flags & PF_W)) {
			/* data segment */
			have_data_segment = true;
			writable_start = MIN(writable_start, seg_start);
			writable_end = MAX(writable_end, seg_end);
		} else {
			have_rodata_segment = true;
			/* read-only segment (not always present) */
			readonly_start = MIN(readonly_start, seg_start);
			readonly_end = MAX(readonly_end, seg_end);
		}
	}

	if (!have_text_segment) {
		/* No text segment??? Must be an error somewhere else. */
		__builtin_trap();
	}
	const void *code_cap = cheri_getpcc();
	const void *rodata_cap = NULL;
	if (!have_rodata_segment) {
		/*
		 * Note: If we don't have a separate rodata segment we also
		 * need to include the text segment in the rodata cap. This is
		 * required since all constants will be part of the read/exec
		 * segment instead of a separate read-only one.
		 */
		readonly_start = text_start;
		readonly_end = text_end;
	}
	rodata_cap = cheri_clearperm(phdr,
	    CHERI_PERM_EXECUTE | CHERI_PERM_STORE | CHERI_PERM_STORE_CAP |
	    CHERI_PERM_STORE_LOCAL_CAP);
	rodata_cap = cheri_setaddress(rodata_cap, readonly_start);
	rodata_cap =
	    cheri_csetbounds(rodata_cap, readonly_end - readonly_start);

	void *data_cap = NULL;
	if (!have_data_segment) {
		/*
		 * There cannot be any capabilities to initialize if there
		 * is no data segment. Set all to NULL to catch errors.
		 *
		 * Note: RELRO segment will be part of a R/W PT_LOAD.
		 */
		rodata_cap = NULL;
		code_cap = NULL;
	} else {
		/* Check that ranges are well-formed */
		if (writable_end < writable_start ||
		    readonly_end < readonly_start ||
		    text_end < text_start)
			__builtin_trap();
		/* Abort if text and writeable overlap: */
		if (MAX(writable_start, text_start) <=
		    MIN(writable_end, text_end)) {
			/* TODO: should we allow a single RWX segment? */
			__builtin_trap();
		}
#ifndef CHERI_INIT_GLOBALS_SUPPORTS_CONSTANT_FLAG
		#pragma message("Warning: cheri_init_globals.h is outdated. Please update LLVM")
		/*
		 * For backwards compat support the old cheri_init_globals.
		 * In this case we must include the rodata segment in the
		 * RW cap since we don't yet have a flag in __cap_relocs for
		 * writable vs readonly data.
		 *
		 * TODO: remove this in a few days/weeks
		 */
		writable_start = MIN(writable_start, readonly_start);
		writable_end = MAX(writable_end, readonly_end);
#endif
		data_cap = cheri_setaddress(phdr, writable_start);
		/* Bound the result and clear execute permissions. */
		data_cap = cheri_clearperm(data_cap, CHERI_PERM_EXECUTE);
		/* TODO: should we use exact setbounds? */
		data_cap =
		    cheri_csetbounds(data_cap, writable_end - writable_start);

		if (!cheri_gettag(data_cap))
			__builtin_trap();
		if (!cheri_gettag(rodata_cap))
			__builtin_trap();
		if (!cheri_gettag(code_cap))
			__builtin_trap();
	}
	crt_init_globals_3(data_cap, code_cap, rodata_cap);
}
#endif /* !defined(POSITION_INDEPENDENT_STARTUP) */
