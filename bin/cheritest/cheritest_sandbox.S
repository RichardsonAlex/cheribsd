/*-
 * Copyright (c) 2013-2016 Robert N. M. Watson
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

	.set noreorder	/* Preserve nops, allow instructions in b-d slots. */
	.set noat	/* Don't use $at automatically. */

/*
 * Landing code within a sandbox.  Various versions with varying levels of
 * technical and moral complexity.
 */

	/*
	 * Sandbox code that simply performs creturn immediately.
	 * Position-independent, no memory access.
	 */
	.text
	.type sandbox_creturn,@function
	.global sandbox_creturn
	.ent sandbox_creturn
sandbox_creturn:

	creturn
	.end sandbox_creturn

	.global sandbox_creturn_end
sandbox_creturn_end:
	.size sandbox_creturn, sandbox_creturn_end - sandbox_creturn
	.size sandbox_creturn_end, 0


	/*
	 * Sandbox code that performs a series of nops before creturn.
	 * Position-independent, no memory access.
	 */
	.text
	.type sandbox_nop_creturn,@function
	.global sandbox_nop_creturn
	.ent sandbox_nop_creturn
sandbox_nop_creturn:

	nop
	nop
	nop
	creturn
	.end sandbox_nop_creturn

	.global sandbox_nop_creturn_end
sandbox_nop_creturn_end:
	.size sandbox_nop_creturn, sandbox_nop_creturn_end - sandbox_nop_creturn
	.size sandbox_nop_creturn_end, 0


	/*
	 * Sandbox code that loads a well-known constant into its return
	 * register before returning.
	 */
	.text
	.type sandbox_dli_creturn,@function
	.global sandbox_dli_creturn
	.ent sandbox_dli_creturn
sandbox_dli_creturn:

	dli	$v0, 0x1234
	creturn
	.end sandbox_dli_creturn

	.global sandbox_dli_creturn_end
sandbox_dli_creturn_end:
	.size sandbox_dli_creturn, sandbox_dli_creturn_end - sandbox_dli_creturn
	.size sandbox_dli_creturn_end, 0
