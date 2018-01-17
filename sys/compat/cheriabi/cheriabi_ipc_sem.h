/*-
 * Copyright (c) 2017 SRI International
 * All rights reserved.
 *
 * This software was developed by SRI International and the University of
 * Cambridge Computer Laboratory under DARPA/AFRL contract FA8750-10-C-0237
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

#ifndef _COMPAT_CHERIABI_IPC_SEM_H_
#define	_COMPAT_CHERIABI_IPC_SEM_H_

#include <sys/cdefs.h>
#include <sys/_types.h>
#include <sys/ipc.h>

struct semid_ds_c {
	struct ipc_perm	 		sem_perm;
	struct sem * __capability	sem_base;
	unsigned short			sem_nsems;
	time_t				sem_otime;
	time_t				sem_ctime;
};

#ifdef _KERNEL
struct semid_kernel_c {
	/* Data structure exposed to user space. */
	struct semid_ds_c		 u;

	/* Kernel-private components of the semaphore. */
	struct label * __capability	label;
	struct ucred * __capability	cred;
};
#endif /* _KERNEL */

#endif /* _COMPAT_CHERIABI_IPC_SEM_H_ */
