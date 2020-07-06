/*
 * System call switch table.
 *
 * DO NOT EDIT-- this file is automatically @generated.
 * $FreeBSD$
 */

#include <sys/param.h>
#include <sys/sysent.h>
#include <sys/sysproto.h>
#include <sys/mount.h>
#include <sys/socket.h>
#include <compat/freebsd32/freebsd32.h>
#include <compat/freebsd32/freebsd32_proto.h>

#define AS(name) (sizeof(struct name) / sizeof(syscallarg_t))

#ifdef COMPAT_43
#define compat(n, name) n, (sy_call_t *)__CONCAT(o,name)
#else
#define compat(n, name) 0, (sy_call_t *)nosys
#endif

#ifdef COMPAT_FREEBSD4
#define compat4(n, name) n, (sy_call_t *)__CONCAT(freebsd4_,name)
#else
#define compat4(n, name) 0, (sy_call_t *)nosys
#endif

#ifdef COMPAT_FREEBSD6
#define compat6(n, name) n, (sy_call_t *)__CONCAT(freebsd6_,name)
#else
#define compat6(n, name) 0, (sy_call_t *)nosys
#endif

#ifdef COMPAT_FREEBSD7
#define compat7(n, name) n, (sy_call_t *)__CONCAT(freebsd7_,name)
#else
#define compat7(n, name) 0, (sy_call_t *)nosys
#endif

#ifdef COMPAT_FREEBSD10
#define compat10(n, name) n, (sy_call_t *)__CONCAT(freebsd10_,name)
#else
#define compat10(n, name) 0, (sy_call_t *)nosys
#endif

#ifdef COMPAT_FREEBSD11
#define compat11(n, name) n, (sy_call_t *)__CONCAT(freebsd11_,name)
#else
#define compat11(n, name) 0, (sy_call_t *)nosys
#endif

#ifdef COMPAT_FREEBSD12
#define compat12(n, name) n, (sy_call_t *)__CONCAT(freebsd12_,name)
#else
#define compat12(n, name) 0, (sy_call_t *)nosys
#endif

/* The casts are bogus but will do for now. */
struct sysent freebsd32_sysent[] = {
#if !defined(PAD64_REQUIRED) && !defined(__amd64__)
#define PAD64_REQUIRED
#endif
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },		/* 0 = syscall */
	{ AS(sys_exit_args), (sy_call_t *)sys_sys_exit, AUE_EXIT, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 1 = exit */
	{ 0, (sy_call_t *)sys_fork, AUE_FORK, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 2 = fork */
	{ AS(read_args), (sy_call_t *)sys_read, AUE_READ, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 3 = read */
	{ AS(write_args), (sy_call_t *)sys_write, AUE_WRITE, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 4 = write */
	{ AS(open_args), (sy_call_t *)sys_open, AUE_OPEN_RWTC, NULL, 0, 0, 0, SY_THR_STATIC },	/* 5 = open */
	{ AS(close_args), (sy_call_t *)sys_close, AUE_CLOSE, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 6 = close */
	{ AS(freebsd32_wait4_args), (sy_call_t *)freebsd32_wait4, AUE_WAIT4, NULL, 0, 0, 0, SY_THR_STATIC },	/* 7 = freebsd32_wait4 */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 8 = obsolete old creat */
	{ AS(link_args), (sy_call_t *)sys_link, AUE_LINK, NULL, 0, 0, 0, SY_THR_STATIC },	/* 9 = link */
	{ AS(unlink_args), (sy_call_t *)sys_unlink, AUE_UNLINK, NULL, 0, 0, 0, SY_THR_STATIC },	/* 10 = unlink */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 11 = obsolete execv */
	{ AS(chdir_args), (sy_call_t *)sys_chdir, AUE_CHDIR, NULL, 0, 0, 0, SY_THR_STATIC },	/* 12 = chdir */
	{ AS(fchdir_args), (sy_call_t *)sys_fchdir, AUE_FCHDIR, NULL, 0, 0, 0, SY_THR_STATIC },	/* 13 = fchdir */
	{ compat11(AS(freebsd11_mknod_args),mknod), AUE_MKNOD, NULL, 0, 0, 0, SY_THR_STATIC },	/* 14 = freebsd11 mknod */
	{ AS(chmod_args), (sy_call_t *)sys_chmod, AUE_CHMOD, NULL, 0, 0, 0, SY_THR_STATIC },	/* 15 = chmod */
	{ AS(chown_args), (sy_call_t *)sys_chown, AUE_CHOWN, NULL, 0, 0, 0, SY_THR_STATIC },	/* 16 = chown */
	{ AS(break_args), (sy_call_t *)sys_break, AUE_NULL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 17 = break */
	{ compat4(AS(freebsd4_freebsd32_getfsstat_args),freebsd32_getfsstat), AUE_GETFSSTAT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 18 = freebsd4 freebsd32_getfsstat */
	{ compat(AS(ofreebsd32_lseek_args),freebsd32_lseek), AUE_LSEEK, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 19 = old freebsd32_lseek */
	{ 0, (sy_call_t *)sys_getpid, AUE_GETPID, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 20 = getpid */
	{ AS(mount_args), (sy_call_t *)sys_mount, AUE_MOUNT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 21 = mount */
	{ AS(unmount_args), (sy_call_t *)sys_unmount, AUE_UMOUNT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 22 = unmount */
	{ AS(setuid_args), (sy_call_t *)sys_setuid, AUE_SETUID, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 23 = setuid */
	{ 0, (sy_call_t *)sys_getuid, AUE_GETUID, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 24 = getuid */
	{ 0, (sy_call_t *)sys_geteuid, AUE_GETEUID, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 25 = geteuid */
	{ AS(freebsd32_ptrace_args), (sy_call_t *)freebsd32_ptrace, AUE_PTRACE, NULL, 0, 0, 0, SY_THR_STATIC },	/* 26 = freebsd32_ptrace */
	{ AS(freebsd32_recvmsg_args), (sy_call_t *)freebsd32_recvmsg, AUE_RECVMSG, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 27 = freebsd32_recvmsg */
	{ AS(freebsd32_sendmsg_args), (sy_call_t *)freebsd32_sendmsg, AUE_SENDMSG, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 28 = freebsd32_sendmsg */
	{ AS(freebsd32_recvfrom_args), (sy_call_t *)freebsd32_recvfrom, AUE_RECVFROM, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 29 = freebsd32_recvfrom */
	{ AS(accept_args), (sy_call_t *)sys_accept, AUE_ACCEPT, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 30 = accept */
	{ AS(getpeername_args), (sy_call_t *)sys_getpeername, AUE_GETPEERNAME, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 31 = getpeername */
	{ AS(getsockname_args), (sy_call_t *)sys_getsockname, AUE_GETSOCKNAME, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 32 = getsockname */
	{ AS(access_args), (sy_call_t *)sys_access, AUE_ACCESS, NULL, 0, 0, 0, SY_THR_STATIC },	/* 33 = access */
	{ AS(chflags_args), (sy_call_t *)sys_chflags, AUE_CHFLAGS, NULL, 0, 0, 0, SY_THR_STATIC },	/* 34 = chflags */
	{ AS(fchflags_args), (sy_call_t *)sys_fchflags, AUE_FCHFLAGS, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 35 = fchflags */
	{ 0, (sy_call_t *)sys_sync, AUE_SYNC, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 36 = sync */
	{ AS(kill_args), (sy_call_t *)sys_kill, AUE_KILL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 37 = kill */
	{ compat(AS(ofreebsd32_stat_args),freebsd32_stat), AUE_STAT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 38 = old freebsd32_stat */
	{ 0, (sy_call_t *)sys_getppid, AUE_GETPPID, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 39 = getppid */
	{ compat(AS(ofreebsd32_lstat_args),freebsd32_lstat), AUE_LSTAT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 40 = old freebsd32_lstat */
	{ AS(dup_args), (sy_call_t *)sys_dup, AUE_DUP, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 41 = dup */
	{ compat10(0,freebsd32_pipe), AUE_PIPE, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 42 = freebsd10 freebsd32_pipe */
	{ 0, (sy_call_t *)sys_getegid, AUE_GETEGID, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 43 = getegid */
	{ AS(profil_args), (sy_call_t *)sys_profil, AUE_PROFILE, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 44 = profil */
	{ AS(ktrace_args), (sy_call_t *)sys_ktrace, AUE_KTRACE, NULL, 0, 0, 0, SY_THR_STATIC },	/* 45 = ktrace */
	{ compat(AS(ofreebsd32_sigaction_args),freebsd32_sigaction), AUE_SIGACTION, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 46 = old freebsd32_sigaction */
	{ 0, (sy_call_t *)sys_getgid, AUE_GETGID, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 47 = getgid */
	{ compat(AS(ofreebsd32_sigprocmask_args),freebsd32_sigprocmask), AUE_SIGPROCMASK, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 48 = old freebsd32_sigprocmask */
	{ AS(getlogin_args), (sy_call_t *)sys_getlogin, AUE_GETLOGIN, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 49 = getlogin */
	{ AS(setlogin_args), (sy_call_t *)sys_setlogin, AUE_SETLOGIN, NULL, 0, 0, 0, SY_THR_STATIC },	/* 50 = setlogin */
	{ AS(acct_args), (sy_call_t *)sys_acct, AUE_ACCT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 51 = acct */
	{ compat(0,freebsd32_sigpending), AUE_SIGPENDING, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 52 = old freebsd32_sigpending */
	{ AS(freebsd32_sigaltstack_args), (sy_call_t *)freebsd32_sigaltstack, AUE_SIGALTSTACK, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 53 = freebsd32_sigaltstack */
	{ AS(freebsd32_ioctl_args), (sy_call_t *)freebsd32_ioctl, AUE_IOCTL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 54 = freebsd32_ioctl */
	{ AS(reboot_args), (sy_call_t *)sys_reboot, AUE_REBOOT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 55 = reboot */
	{ AS(revoke_args), (sy_call_t *)sys_revoke, AUE_REVOKE, NULL, 0, 0, 0, SY_THR_STATIC },	/* 56 = revoke */
	{ AS(symlink_args), (sy_call_t *)sys_symlink, AUE_SYMLINK, NULL, 0, 0, 0, SY_THR_STATIC },	/* 57 = symlink */
	{ AS(readlink_args), (sy_call_t *)sys_readlink, AUE_READLINK, NULL, 0, 0, 0, SY_THR_STATIC },	/* 58 = readlink */
	{ AS(freebsd32_execve_args), (sy_call_t *)freebsd32_execve, AUE_EXECVE, NULL, 0, 0, 0, SY_THR_STATIC },	/* 59 = freebsd32_execve */
	{ AS(umask_args), (sy_call_t *)sys_umask, AUE_UMASK, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 60 = umask */
	{ AS(chroot_args), (sy_call_t *)sys_chroot, AUE_CHROOT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 61 = chroot */
	{ compat(AS(ofreebsd32_fstat_args),freebsd32_fstat), AUE_FSTAT, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 62 = old freebsd32_fstat */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 63 = obsolete ogetkerninfo */
	{ compat(AS(ofreebsd32_getpagesize_args),freebsd32_getpagesize), AUE_NULL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 64 = old freebsd32_getpagesize */
	{ AS(msync_args), (sy_call_t *)sys_msync, AUE_MSYNC, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 65 = msync */
	{ 0, (sy_call_t *)sys_vfork, AUE_VFORK, NULL, 0, 0, 0, SY_THR_STATIC },	/* 66 = vfork */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 67 = obsolete vread */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 68 = obsolete vwrite */
	{ AS(sbrk_args), (sy_call_t *)sys_sbrk, AUE_SBRK, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 69 = sbrk */
	{ AS(sstk_args), (sy_call_t *)sys_sstk, AUE_SSTK, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 70 = sstk */
	{ compat(AS(ommap_args),mmap), AUE_MMAP, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 71 = old mmap */
	{ compat11(AS(freebsd11_vadvise_args),vadvise), AUE_O_VADVISE, NULL, 0, 0, 0, SY_THR_STATIC },	/* 72 = freebsd11 vadvise */
	{ AS(munmap_args), (sy_call_t *)sys_munmap, AUE_MUNMAP, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 73 = munmap */
	{ AS(freebsd32_mprotect_args), (sy_call_t *)freebsd32_mprotect, AUE_MPROTECT, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 74 = freebsd32_mprotect */
	{ AS(madvise_args), (sy_call_t *)sys_madvise, AUE_MADVISE, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 75 = madvise */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 76 = obsolete vhangup */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 77 = obsolete vlimit */
	{ AS(mincore_args), (sy_call_t *)sys_mincore, AUE_MINCORE, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 78 = mincore */
	{ AS(getgroups_args), (sy_call_t *)sys_getgroups, AUE_GETGROUPS, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 79 = getgroups */
	{ AS(setgroups_args), (sy_call_t *)sys_setgroups, AUE_SETGROUPS, NULL, 0, 0, 0, SY_THR_STATIC },	/* 80 = setgroups */
	{ 0, (sy_call_t *)sys_getpgrp, AUE_GETPGRP, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 81 = getpgrp */
	{ AS(setpgid_args), (sy_call_t *)sys_setpgid, AUE_SETPGRP, NULL, 0, 0, 0, SY_THR_STATIC },	/* 82 = setpgid */
	{ AS(freebsd32_setitimer_args), (sy_call_t *)freebsd32_setitimer, AUE_SETITIMER, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 83 = freebsd32_setitimer */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 84 = obsolete owait */
	{ AS(swapon_args), (sy_call_t *)sys_swapon, AUE_SWAPON, NULL, 0, 0, 0, SY_THR_STATIC },	/* 85 = swapon */
	{ AS(freebsd32_getitimer_args), (sy_call_t *)freebsd32_getitimer, AUE_GETITIMER, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 86 = freebsd32_getitimer */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 87 = obsolete ogethostname */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 88 = obsolete osethostname */
	{ 0, (sy_call_t *)sys_getdtablesize, AUE_GETDTABLESIZE, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 89 = getdtablesize */
	{ AS(dup2_args), (sy_call_t *)sys_dup2, AUE_DUP2, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 90 = dup2 */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 91 = getdopt */
	{ AS(freebsd32_fcntl_args), (sy_call_t *)freebsd32_fcntl, AUE_FCNTL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 92 = freebsd32_fcntl */
	{ AS(freebsd32_select_args), (sy_call_t *)freebsd32_select, AUE_SELECT, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 93 = freebsd32_select */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 94 = setdopt */
	{ AS(fsync_args), (sy_call_t *)sys_fsync, AUE_FSYNC, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 95 = fsync */
	{ AS(setpriority_args), (sy_call_t *)sys_setpriority, AUE_SETPRIORITY, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 96 = setpriority */
	{ AS(socket_args), (sy_call_t *)sys_socket, AUE_SOCKET, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 97 = socket */
	{ AS(connect_args), (sy_call_t *)sys_connect, AUE_CONNECT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 98 = connect */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 99 = obsolete oaccept */
	{ AS(getpriority_args), (sy_call_t *)sys_getpriority, AUE_GETPRIORITY, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 100 = getpriority */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 101 = obsolete osend */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 102 = obsolete orecv */
	{ compat(AS(ofreebsd32_sigreturn_args),freebsd32_sigreturn), AUE_SIGRETURN, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 103 = old freebsd32_sigreturn */
	{ AS(bind_args), (sy_call_t *)sys_bind, AUE_BIND, NULL, 0, 0, 0, SY_THR_STATIC },	/* 104 = bind */
	{ AS(setsockopt_args), (sy_call_t *)sys_setsockopt, AUE_SETSOCKOPT, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 105 = setsockopt */
	{ AS(listen_args), (sy_call_t *)sys_listen, AUE_LISTEN, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 106 = listen */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 107 = obsolete vtimes */
	{ compat(AS(ofreebsd32_sigvec_args),freebsd32_sigvec), AUE_O_SIGVEC, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 108 = old freebsd32_sigvec */
	{ compat(AS(ofreebsd32_sigblock_args),freebsd32_sigblock), AUE_O_SIGBLOCK, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 109 = old freebsd32_sigblock */
	{ compat(AS(ofreebsd32_sigsetmask_args),freebsd32_sigsetmask), AUE_O_SIGSETMASK, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 110 = old freebsd32_sigsetmask */
	{ compat(AS(ofreebsd32_sigsuspend_args),freebsd32_sigsuspend), AUE_SIGSUSPEND, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 111 = old freebsd32_sigsuspend */
	{ compat(AS(ofreebsd32_sigstack_args),freebsd32_sigstack), AUE_O_SIGSTACK, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 112 = old freebsd32_sigstack */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 113 = obsolete orecvmsg */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 114 = obsolete osendmsg */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 115 = obsolete vtrace */
	{ AS(freebsd32_gettimeofday_args), (sy_call_t *)freebsd32_gettimeofday, AUE_GETTIMEOFDAY, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 116 = freebsd32_gettimeofday */
	{ AS(freebsd32_getrusage_args), (sy_call_t *)freebsd32_getrusage, AUE_GETRUSAGE, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 117 = freebsd32_getrusage */
	{ AS(getsockopt_args), (sy_call_t *)sys_getsockopt, AUE_GETSOCKOPT, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 118 = getsockopt */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 119 = resuba */
	{ AS(freebsd32_readv_args), (sy_call_t *)freebsd32_readv, AUE_READV, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 120 = freebsd32_readv */
	{ AS(freebsd32_writev_args), (sy_call_t *)freebsd32_writev, AUE_WRITEV, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 121 = freebsd32_writev */
	{ AS(freebsd32_settimeofday_args), (sy_call_t *)freebsd32_settimeofday, AUE_SETTIMEOFDAY, NULL, 0, 0, 0, SY_THR_STATIC },	/* 122 = freebsd32_settimeofday */
	{ AS(fchown_args), (sy_call_t *)sys_fchown, AUE_FCHOWN, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 123 = fchown */
	{ AS(fchmod_args), (sy_call_t *)sys_fchmod, AUE_FCHMOD, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 124 = fchmod */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 125 = obsolete orecvfrom */
	{ AS(setreuid_args), (sy_call_t *)sys_setreuid, AUE_SETREUID, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 126 = setreuid */
	{ AS(setregid_args), (sy_call_t *)sys_setregid, AUE_SETREGID, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 127 = setregid */
	{ AS(rename_args), (sy_call_t *)sys_rename, AUE_RENAME, NULL, 0, 0, 0, SY_THR_STATIC },	/* 128 = rename */
	{ compat(AS(otruncate_args),truncate), AUE_TRUNCATE, NULL, 0, 0, 0, SY_THR_STATIC },	/* 129 = old truncate */
	{ compat(AS(oftruncate_args),ftruncate), AUE_FTRUNCATE, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 130 = old ftruncate */
	{ AS(flock_args), (sy_call_t *)sys_flock, AUE_FLOCK, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 131 = flock */
	{ AS(mkfifo_args), (sy_call_t *)sys_mkfifo, AUE_MKFIFO, NULL, 0, 0, 0, SY_THR_STATIC },	/* 132 = mkfifo */
	{ AS(sendto_args), (sy_call_t *)sys_sendto, AUE_SENDTO, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 133 = sendto */
	{ AS(shutdown_args), (sy_call_t *)sys_shutdown, AUE_SHUTDOWN, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 134 = shutdown */
	{ AS(socketpair_args), (sy_call_t *)sys_socketpair, AUE_SOCKETPAIR, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 135 = socketpair */
	{ AS(mkdir_args), (sy_call_t *)sys_mkdir, AUE_MKDIR, NULL, 0, 0, 0, SY_THR_STATIC },	/* 136 = mkdir */
	{ AS(rmdir_args), (sy_call_t *)sys_rmdir, AUE_RMDIR, NULL, 0, 0, 0, SY_THR_STATIC },	/* 137 = rmdir */
	{ AS(freebsd32_utimes_args), (sy_call_t *)freebsd32_utimes, AUE_UTIMES, NULL, 0, 0, 0, SY_THR_STATIC },	/* 138 = freebsd32_utimes */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 139 = obsolete 4.2 sigreturn */
	{ AS(freebsd32_adjtime_args), (sy_call_t *)freebsd32_adjtime, AUE_ADJTIME, NULL, 0, 0, 0, SY_THR_STATIC },	/* 140 = freebsd32_adjtime */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 141 = obsolete ogetpeername */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 142 = obsolete ogethostid */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 143 = obsolete sethostid */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 144 = obsolete getrlimit */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 145 = obsolete setrlimit */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 146 = obsolete killpg */
	{ 0, (sy_call_t *)sys_setsid, AUE_SETSID, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 147 = setsid */
	{ AS(quotactl_args), (sy_call_t *)sys_quotactl, AUE_QUOTACTL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 148 = quotactl */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 149 = obsolete oquota */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 150 = obsolete ogetsockname */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 151 = sem_lock */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 152 = sem_wakeup */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 153 = asyncdaemon */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 154 = nlm_syscall */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 155 = nfssvc */
	{ compat(AS(ofreebsd32_getdirentries_args),freebsd32_getdirentries), AUE_GETDIRENTRIES, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 156 = old freebsd32_getdirentries */
	{ compat4(AS(freebsd4_freebsd32_statfs_args),freebsd32_statfs), AUE_STATFS, NULL, 0, 0, 0, SY_THR_STATIC },	/* 157 = freebsd4 freebsd32_statfs */
	{ compat4(AS(freebsd4_freebsd32_fstatfs_args),freebsd32_fstatfs), AUE_FSTATFS, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 158 = freebsd4 freebsd32_fstatfs */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 159 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 160 = lgetfh */
	{ AS(getfh_args), (sy_call_t *)sys_getfh, AUE_NFS_GETFH, NULL, 0, 0, 0, SY_THR_STATIC },	/* 161 = getfh */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 162 = obsolete getdomainname */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 163 = obsolete setdomainname */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 164 = obsolete uname */
	{ AS(freebsd32_sysarch_args), (sy_call_t *)freebsd32_sysarch, AUE_SYSARCH, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 165 = freebsd32_sysarch */
	{ AS(rtprio_args), (sy_call_t *)sys_rtprio, AUE_RTPRIO, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 166 = rtprio */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 167 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 168 = nosys */
	{ AS(freebsd32_semsys_args), (sy_call_t *)lkmressys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },	/* 169 = freebsd32_semsys */
	{ AS(freebsd32_msgsys_args), (sy_call_t *)lkmressys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },	/* 170 = freebsd32_msgsys */
	{ AS(freebsd32_shmsys_args), (sy_call_t *)lkmressys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },	/* 171 = freebsd32_shmsys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 172 = nosys */
	{ compat6(AS(freebsd6_freebsd32_pread_args),freebsd32_pread), AUE_PREAD, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 173 = freebsd6 freebsd32_pread */
	{ compat6(AS(freebsd6_freebsd32_pwrite_args),freebsd32_pwrite), AUE_PWRITE, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 174 = freebsd6 freebsd32_pwrite */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 175 = nosys */
	{ AS(ntp_adjtime_args), (sy_call_t *)sys_ntp_adjtime, AUE_NTP_ADJTIME, NULL, 0, 0, 0, SY_THR_STATIC },	/* 176 = ntp_adjtime */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 177 = sfork */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 178 = getdescriptor */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 179 = setdescriptor */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 180 = nosys */
	{ AS(setgid_args), (sy_call_t *)sys_setgid, AUE_SETGID, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 181 = setgid */
	{ AS(setegid_args), (sy_call_t *)sys_setegid, AUE_SETEGID, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 182 = setegid */
	{ AS(seteuid_args), (sy_call_t *)sys_seteuid, AUE_SETEUID, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 183 = seteuid */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 184 = obsolete lfs_bmapv */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 185 = obsolete lfs_markv */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 186 = obsolete lfs_segclean */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 187 = obsolete lfs_segwait */
	{ compat11(AS(freebsd11_freebsd32_stat_args),freebsd32_stat), AUE_STAT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 188 = freebsd11 freebsd32_stat */
	{ compat11(AS(freebsd11_freebsd32_fstat_args),freebsd32_fstat), AUE_FSTAT, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 189 = freebsd11 freebsd32_fstat */
	{ compat11(AS(freebsd11_freebsd32_lstat_args),freebsd32_lstat), AUE_LSTAT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 190 = freebsd11 freebsd32_lstat */
	{ AS(pathconf_args), (sy_call_t *)sys_pathconf, AUE_PATHCONF, NULL, 0, 0, 0, SY_THR_STATIC },	/* 191 = pathconf */
	{ AS(fpathconf_args), (sy_call_t *)sys_fpathconf, AUE_FPATHCONF, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 192 = fpathconf */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 193 = nosys */
	{ AS(__getrlimit_args), (sy_call_t *)sys_getrlimit, AUE_GETRLIMIT, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 194 = getrlimit */
	{ AS(__setrlimit_args), (sy_call_t *)sys_setrlimit, AUE_SETRLIMIT, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 195 = setrlimit */
	{ compat11(AS(freebsd11_freebsd32_getdirentries_args),freebsd32_getdirentries), AUE_GETDIRENTRIES, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 196 = freebsd11 freebsd32_getdirentries */
	{ compat6(AS(freebsd6_freebsd32_mmap_args),freebsd32_mmap), AUE_MMAP, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 197 = freebsd6 freebsd32_mmap */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },		/* 198 = __syscall */
	{ compat6(AS(freebsd6_freebsd32_lseek_args),freebsd32_lseek), AUE_LSEEK, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 199 = freebsd6 freebsd32_lseek */
	{ compat6(AS(freebsd6_freebsd32_truncate_args),freebsd32_truncate), AUE_TRUNCATE, NULL, 0, 0, 0, SY_THR_STATIC },	/* 200 = freebsd6 freebsd32_truncate */
	{ compat6(AS(freebsd6_freebsd32_ftruncate_args),freebsd32_ftruncate), AUE_FTRUNCATE, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 201 = freebsd6 freebsd32_ftruncate */
	{ AS(freebsd32___sysctl_args), (sy_call_t *)freebsd32___sysctl, AUE_SYSCTL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 202 = freebsd32___sysctl */
	{ AS(mlock_args), (sy_call_t *)sys_mlock, AUE_MLOCK, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 203 = mlock */
	{ AS(munlock_args), (sy_call_t *)sys_munlock, AUE_MUNLOCK, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 204 = munlock */
	{ AS(undelete_args), (sy_call_t *)sys_undelete, AUE_UNDELETE, NULL, 0, 0, 0, SY_THR_STATIC },	/* 205 = undelete */
	{ AS(freebsd32_futimes_args), (sy_call_t *)freebsd32_futimes, AUE_FUTIMES, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 206 = freebsd32_futimes */
	{ AS(getpgid_args), (sy_call_t *)sys_getpgid, AUE_GETPGID, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 207 = getpgid */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 208 = nosys */
	{ AS(poll_args), (sy_call_t *)sys_poll, AUE_POLL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 209 = poll */
	{ AS(nosys_args), (sy_call_t *)lkmnosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },	/* 210 = lkmnosys */
	{ AS(nosys_args), (sy_call_t *)lkmnosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },	/* 211 = lkmnosys */
	{ AS(nosys_args), (sy_call_t *)lkmnosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },	/* 212 = lkmnosys */
	{ AS(nosys_args), (sy_call_t *)lkmnosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },	/* 213 = lkmnosys */
	{ AS(nosys_args), (sy_call_t *)lkmnosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },	/* 214 = lkmnosys */
	{ AS(nosys_args), (sy_call_t *)lkmnosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },	/* 215 = lkmnosys */
	{ AS(nosys_args), (sy_call_t *)lkmnosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },	/* 216 = lkmnosys */
	{ AS(nosys_args), (sy_call_t *)lkmnosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },	/* 217 = lkmnosys */
	{ AS(nosys_args), (sy_call_t *)lkmnosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },	/* 218 = lkmnosys */
	{ AS(nosys_args), (sy_call_t *)lkmnosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },	/* 219 = lkmnosys */
	{ 0, (sy_call_t *)lkmressys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },		/* 220 = freebsd7 freebsd32_semctl */
	{ AS(semget_args), (sy_call_t *)lkmressys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },	/* 221 = semget */
	{ AS(semop_args), (sy_call_t *)lkmressys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },	/* 222 = semop */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 223 = obsolete semconfig */
	{ 0, (sy_call_t *)lkmressys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },		/* 224 = freebsd7 freebsd32_msgctl */
	{ AS(msgget_args), (sy_call_t *)lkmressys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },	/* 225 = msgget */
	{ AS(freebsd32_msgsnd_args), (sy_call_t *)lkmressys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },	/* 226 = freebsd32_msgsnd */
	{ AS(freebsd32_msgrcv_args), (sy_call_t *)lkmressys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },	/* 227 = freebsd32_msgrcv */
	{ AS(shmat_args), (sy_call_t *)lkmressys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },	/* 228 = shmat */
	{ 0, (sy_call_t *)lkmressys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },		/* 229 = freebsd7 freebsd32_shmctl */
	{ AS(shmdt_args), (sy_call_t *)lkmressys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },	/* 230 = shmdt */
	{ AS(shmget_args), (sy_call_t *)lkmressys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },	/* 231 = shmget */
	{ AS(freebsd32_clock_gettime_args), (sy_call_t *)freebsd32_clock_gettime, AUE_NULL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 232 = freebsd32_clock_gettime */
	{ AS(freebsd32_clock_settime_args), (sy_call_t *)freebsd32_clock_settime, AUE_CLOCK_SETTIME, NULL, 0, 0, 0, SY_THR_STATIC },	/* 233 = freebsd32_clock_settime */
	{ AS(freebsd32_clock_getres_args), (sy_call_t *)freebsd32_clock_getres, AUE_NULL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 234 = freebsd32_clock_getres */
	{ AS(freebsd32_ktimer_create_args), (sy_call_t *)freebsd32_ktimer_create, AUE_NULL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 235 = freebsd32_ktimer_create */
	{ AS(ktimer_delete_args), (sy_call_t *)sys_ktimer_delete, AUE_NULL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 236 = ktimer_delete */
	{ AS(freebsd32_ktimer_settime_args), (sy_call_t *)freebsd32_ktimer_settime, AUE_NULL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 237 = freebsd32_ktimer_settime */
	{ AS(freebsd32_ktimer_gettime_args), (sy_call_t *)freebsd32_ktimer_gettime, AUE_NULL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 238 = freebsd32_ktimer_gettime */
	{ AS(ktimer_getoverrun_args), (sy_call_t *)sys_ktimer_getoverrun, AUE_NULL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 239 = ktimer_getoverrun */
	{ AS(freebsd32_nanosleep_args), (sy_call_t *)freebsd32_nanosleep, AUE_NULL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 240 = freebsd32_nanosleep */
	{ AS(ffclock_getcounter_args), (sy_call_t *)sys_ffclock_getcounter, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 241 = ffclock_getcounter */
	{ AS(ffclock_setestimate_args), (sy_call_t *)sys_ffclock_setestimate, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 242 = ffclock_setestimate */
	{ AS(ffclock_getestimate_args), (sy_call_t *)sys_ffclock_getestimate, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 243 = ffclock_getestimate */
	{ AS(freebsd32_clock_nanosleep_args), (sy_call_t *)freebsd32_clock_nanosleep, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 244 = freebsd32_clock_nanosleep */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 245 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 246 = nosys */
	{ AS(freebsd32_clock_getcpuclockid2_args), (sy_call_t *)freebsd32_clock_getcpuclockid2, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 247 = freebsd32_clock_getcpuclockid2 */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 248 = ntp_gettime */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 249 = nosys */
	{ AS(minherit_args), (sy_call_t *)sys_minherit, AUE_MINHERIT, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 250 = minherit */
	{ AS(rfork_args), (sy_call_t *)sys_rfork, AUE_RFORK, NULL, 0, 0, 0, SY_THR_STATIC },	/* 251 = rfork */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 252 = obsolete openbsd_poll */
	{ 0, (sy_call_t *)sys_issetugid, AUE_ISSETUGID, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 253 = issetugid */
	{ AS(lchown_args), (sy_call_t *)sys_lchown, AUE_LCHOWN, NULL, 0, 0, 0, SY_THR_STATIC },	/* 254 = lchown */
	{ AS(freebsd32_aio_read_args), (sy_call_t *)freebsd32_aio_read, AUE_AIO_READ, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 255 = freebsd32_aio_read */
	{ AS(freebsd32_aio_write_args), (sy_call_t *)freebsd32_aio_write, AUE_AIO_WRITE, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 256 = freebsd32_aio_write */
	{ AS(freebsd32_lio_listio_args), (sy_call_t *)freebsd32_lio_listio, AUE_LIO_LISTIO, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 257 = freebsd32_lio_listio */
	{ AS(kbounce_args), (sy_call_t *)sys_kbounce, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 258 = kbounce */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 259 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 260 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 261 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 262 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 263 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 264 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 265 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 266 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 267 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 268 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 269 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 270 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 271 = nosys */
	{ compat11(AS(freebsd11_freebsd32_getdents_args),freebsd32_getdents), AUE_O_GETDENTS, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 272 = freebsd11 freebsd32_getdents */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 273 = nosys */
	{ AS(lchmod_args), (sy_call_t *)sys_lchmod, AUE_LCHMOD, NULL, 0, 0, 0, SY_THR_STATIC },	/* 274 = lchmod */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 275 = obsolete netbsd_lchown */
	{ AS(freebsd32_lutimes_args), (sy_call_t *)freebsd32_lutimes, AUE_LUTIMES, NULL, 0, 0, 0, SY_THR_STATIC },	/* 276 = freebsd32_lutimes */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 277 = obsolete netbsd_msync */
	{ compat11(AS(freebsd11_nstat_args),nstat), AUE_STAT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 278 = freebsd11 nstat */
	{ compat11(AS(freebsd11_nfstat_args),nfstat), AUE_FSTAT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 279 = freebsd11 nfstat */
	{ compat11(AS(freebsd11_nlstat_args),nlstat), AUE_LSTAT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 280 = freebsd11 nlstat */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 281 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 282 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 283 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 284 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 285 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 286 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 287 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 288 = nosys */
	{ AS(freebsd32_preadv_args), (sy_call_t *)freebsd32_preadv, AUE_PREADV, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 289 = freebsd32_preadv */
	{ AS(freebsd32_pwritev_args), (sy_call_t *)freebsd32_pwritev, AUE_PWRITEV, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 290 = freebsd32_pwritev */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 291 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 292 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 293 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 294 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 295 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 296 = nosys */
	{ compat4(AS(freebsd4_freebsd32_fhstatfs_args),freebsd32_fhstatfs), AUE_FHSTATFS, NULL, 0, 0, 0, SY_THR_STATIC },	/* 297 = freebsd4 freebsd32_fhstatfs */
	{ AS(fhopen_args), (sy_call_t *)sys_fhopen, AUE_FHOPEN, NULL, 0, 0, 0, SY_THR_STATIC },	/* 298 = fhopen */
	{ compat11(AS(freebsd11_freebsd32_fhstat_args),freebsd32_fhstat), AUE_FHSTAT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 299 = freebsd11 freebsd32_fhstat */
	{ AS(modnext_args), (sy_call_t *)sys_modnext, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 300 = modnext */
	{ AS(freebsd32_modstat_args), (sy_call_t *)freebsd32_modstat, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 301 = freebsd32_modstat */
	{ AS(modfnext_args), (sy_call_t *)sys_modfnext, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 302 = modfnext */
	{ AS(modfind_args), (sy_call_t *)sys_modfind, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 303 = modfind */
	{ AS(kldload_args), (sy_call_t *)sys_kldload, AUE_MODLOAD, NULL, 0, 0, 0, SY_THR_STATIC },	/* 304 = kldload */
	{ AS(kldunload_args), (sy_call_t *)sys_kldunload, AUE_MODUNLOAD, NULL, 0, 0, 0, SY_THR_STATIC },	/* 305 = kldunload */
	{ AS(kldfind_args), (sy_call_t *)sys_kldfind, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 306 = kldfind */
	{ AS(kldnext_args), (sy_call_t *)sys_kldnext, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 307 = kldnext */
	{ AS(freebsd32_kldstat_args), (sy_call_t *)freebsd32_kldstat, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 308 = freebsd32_kldstat */
	{ AS(kldfirstmod_args), (sy_call_t *)sys_kldfirstmod, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 309 = kldfirstmod */
	{ AS(getsid_args), (sy_call_t *)sys_getsid, AUE_GETSID, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 310 = getsid */
	{ AS(setresuid_args), (sy_call_t *)sys_setresuid, AUE_SETRESUID, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 311 = setresuid */
	{ AS(setresgid_args), (sy_call_t *)sys_setresgid, AUE_SETRESGID, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 312 = setresgid */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 313 = obsolete signanosleep */
	{ AS(freebsd32_aio_return_args), (sy_call_t *)freebsd32_aio_return, AUE_AIO_RETURN, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 314 = freebsd32_aio_return */
	{ AS(freebsd32_aio_suspend_args), (sy_call_t *)freebsd32_aio_suspend, AUE_AIO_SUSPEND, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 315 = freebsd32_aio_suspend */
	{ AS(freebsd32_aio_cancel_args), (sy_call_t *)freebsd32_aio_cancel, AUE_AIO_CANCEL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 316 = freebsd32_aio_cancel */
	{ AS(freebsd32_aio_error_args), (sy_call_t *)freebsd32_aio_error, AUE_AIO_ERROR, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 317 = freebsd32_aio_error */
	{ compat6(AS(freebsd6_freebsd32_aio_read_args),freebsd32_aio_read), AUE_AIO_READ, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 318 = freebsd6 freebsd32_aio_read */
	{ compat6(AS(freebsd6_freebsd32_aio_write_args),freebsd32_aio_write), AUE_AIO_WRITE, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 319 = freebsd6 freebsd32_aio_write */
	{ compat6(AS(freebsd6_freebsd32_lio_listio_args),freebsd32_lio_listio), AUE_LIO_LISTIO, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 320 = freebsd6 freebsd32_lio_listio */
	{ 0, (sy_call_t *)sys_yield, AUE_NULL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 321 = yield */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 322 = obsolete thr_sleep */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 323 = obsolete thr_wakeup */
	{ AS(mlockall_args), (sy_call_t *)sys_mlockall, AUE_MLOCKALL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 324 = mlockall */
	{ 0, (sy_call_t *)sys_munlockall, AUE_MUNLOCKALL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 325 = munlockall */
	{ AS(__getcwd_args), (sy_call_t *)sys___getcwd, AUE_GETCWD, NULL, 0, 0, 0, SY_THR_STATIC },	/* 326 = __getcwd */
	{ AS(sched_setparam_args), (sy_call_t *)sys_sched_setparam, AUE_NULL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 327 = sched_setparam */
	{ AS(sched_getparam_args), (sy_call_t *)sys_sched_getparam, AUE_NULL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 328 = sched_getparam */
	{ AS(sched_setscheduler_args), (sy_call_t *)sys_sched_setscheduler, AUE_NULL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 329 = sched_setscheduler */
	{ AS(sched_getscheduler_args), (sy_call_t *)sys_sched_getscheduler, AUE_NULL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 330 = sched_getscheduler */
	{ 0, (sy_call_t *)sys_sched_yield, AUE_NULL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 331 = sched_yield */
	{ AS(sched_get_priority_max_args), (sy_call_t *)sys_sched_get_priority_max, AUE_NULL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 332 = sched_get_priority_max */
	{ AS(sched_get_priority_min_args), (sy_call_t *)sys_sched_get_priority_min, AUE_NULL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 333 = sched_get_priority_min */
	{ AS(freebsd32_sched_rr_get_interval_args), (sy_call_t *)freebsd32_sched_rr_get_interval, AUE_NULL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 334 = freebsd32_sched_rr_get_interval */
	{ AS(utrace_args), (sy_call_t *)sys_utrace, AUE_NULL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 335 = utrace */
	{ compat4(AS(freebsd4_freebsd32_sendfile_args),freebsd32_sendfile), AUE_SENDFILE, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 336 = freebsd4 freebsd32_sendfile */
	{ AS(kldsym_args), (sy_call_t *)sys_kldsym, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 337 = kldsym */
	{ AS(freebsd32_jail_args), (sy_call_t *)freebsd32_jail, AUE_JAIL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 338 = freebsd32_jail */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 339 = pioctl */
	{ AS(sigprocmask_args), (sy_call_t *)sys_sigprocmask, AUE_SIGPROCMASK, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 340 = sigprocmask */
	{ AS(sigsuspend_args), (sy_call_t *)sys_sigsuspend, AUE_SIGSUSPEND, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 341 = sigsuspend */
	{ compat4(AS(freebsd4_freebsd32_sigaction_args),freebsd32_sigaction), AUE_SIGACTION, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 342 = freebsd4 freebsd32_sigaction */
	{ AS(sigpending_args), (sy_call_t *)sys_sigpending, AUE_SIGPENDING, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 343 = sigpending */
	{ compat4(AS(freebsd4_freebsd32_sigreturn_args),freebsd32_sigreturn), AUE_SIGRETURN, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 344 = freebsd4 freebsd32_sigreturn */
	{ AS(freebsd32_sigtimedwait_args), (sy_call_t *)freebsd32_sigtimedwait, AUE_SIGWAIT, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 345 = freebsd32_sigtimedwait */
	{ AS(freebsd32_sigwaitinfo_args), (sy_call_t *)freebsd32_sigwaitinfo, AUE_NULL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 346 = freebsd32_sigwaitinfo */
	{ AS(__acl_get_file_args), (sy_call_t *)sys___acl_get_file, AUE_ACL_GET_FILE, NULL, 0, 0, 0, SY_THR_STATIC },	/* 347 = __acl_get_file */
	{ AS(__acl_set_file_args), (sy_call_t *)sys___acl_set_file, AUE_ACL_SET_FILE, NULL, 0, 0, 0, SY_THR_STATIC },	/* 348 = __acl_set_file */
	{ AS(__acl_get_fd_args), (sy_call_t *)sys___acl_get_fd, AUE_ACL_GET_FD, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 349 = __acl_get_fd */
	{ AS(__acl_set_fd_args), (sy_call_t *)sys___acl_set_fd, AUE_ACL_SET_FD, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 350 = __acl_set_fd */
	{ AS(__acl_delete_file_args), (sy_call_t *)sys___acl_delete_file, AUE_ACL_DELETE_FILE, NULL, 0, 0, 0, SY_THR_STATIC },	/* 351 = __acl_delete_file */
	{ AS(__acl_delete_fd_args), (sy_call_t *)sys___acl_delete_fd, AUE_ACL_DELETE_FD, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 352 = __acl_delete_fd */
	{ AS(__acl_aclcheck_file_args), (sy_call_t *)sys___acl_aclcheck_file, AUE_ACL_CHECK_FILE, NULL, 0, 0, 0, SY_THR_STATIC },	/* 353 = __acl_aclcheck_file */
	{ AS(__acl_aclcheck_fd_args), (sy_call_t *)sys___acl_aclcheck_fd, AUE_ACL_CHECK_FD, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 354 = __acl_aclcheck_fd */
	{ AS(extattrctl_args), (sy_call_t *)sys_extattrctl, AUE_EXTATTRCTL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 355 = extattrctl */
	{ AS(extattr_set_file_args), (sy_call_t *)sys_extattr_set_file, AUE_EXTATTR_SET_FILE, NULL, 0, 0, 0, SY_THR_STATIC },	/* 356 = extattr_set_file */
	{ AS(extattr_get_file_args), (sy_call_t *)sys_extattr_get_file, AUE_EXTATTR_GET_FILE, NULL, 0, 0, 0, SY_THR_STATIC },	/* 357 = extattr_get_file */
	{ AS(extattr_delete_file_args), (sy_call_t *)sys_extattr_delete_file, AUE_EXTATTR_DELETE_FILE, NULL, 0, 0, 0, SY_THR_STATIC },	/* 358 = extattr_delete_file */
	{ AS(freebsd32_aio_waitcomplete_args), (sy_call_t *)freebsd32_aio_waitcomplete, AUE_AIO_WAITCOMPLETE, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 359 = freebsd32_aio_waitcomplete */
	{ AS(getresuid_args), (sy_call_t *)sys_getresuid, AUE_GETRESUID, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 360 = getresuid */
	{ AS(getresgid_args), (sy_call_t *)sys_getresgid, AUE_GETRESGID, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 361 = getresgid */
	{ 0, (sy_call_t *)sys_kqueue, AUE_KQUEUE, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 362 = kqueue */
	{ compat11(AS(freebsd11_freebsd32_kevent_args),freebsd32_kevent), AUE_KEVENT, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 363 = freebsd11 freebsd32_kevent */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 364 = obsolete __cap_get_proc */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 365 = obsolete __cap_set_proc */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 366 = obsolete __cap_get_fd */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 367 = obsolete __cap_get_file */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 368 = obsolete __cap_set_fd */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 369 = obsolete __cap_set_file */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 370 = nosys */
	{ AS(extattr_set_fd_args), (sy_call_t *)sys_extattr_set_fd, AUE_EXTATTR_SET_FD, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 371 = extattr_set_fd */
	{ AS(extattr_get_fd_args), (sy_call_t *)sys_extattr_get_fd, AUE_EXTATTR_GET_FD, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 372 = extattr_get_fd */
	{ AS(extattr_delete_fd_args), (sy_call_t *)sys_extattr_delete_fd, AUE_EXTATTR_DELETE_FD, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 373 = extattr_delete_fd */
	{ AS(__setugid_args), (sy_call_t *)sys___setugid, AUE_SETUGID, NULL, 0, 0, 0, SY_THR_STATIC },	/* 374 = __setugid */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 375 = obsolete nfsclnt */
	{ AS(eaccess_args), (sy_call_t *)sys_eaccess, AUE_EACCESS, NULL, 0, 0, 0, SY_THR_STATIC },	/* 376 = eaccess */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 377 = afs_syscall */
	{ AS(freebsd32_nmount_args), (sy_call_t *)freebsd32_nmount, AUE_NMOUNT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 378 = freebsd32_nmount */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 379 = obsolete kse_exit */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 380 = obsolete kse_wakeup */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 381 = obsolete kse_create */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 382 = obsolete kse_thr_interrupt */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 383 = obsolete kse_release */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 384 = __mac_get_proc */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 385 = __mac_set_proc */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 386 = __mac_get_fd */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 387 = __mac_get_file */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 388 = __mac_set_fd */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 389 = __mac_set_file */
	{ AS(kenv_args), (sy_call_t *)sys_kenv, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 390 = kenv */
	{ AS(lchflags_args), (sy_call_t *)sys_lchflags, AUE_LCHFLAGS, NULL, 0, 0, 0, SY_THR_STATIC },	/* 391 = lchflags */
	{ AS(uuidgen_args), (sy_call_t *)sys_uuidgen, AUE_NULL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 392 = uuidgen */
	{ AS(freebsd32_sendfile_args), (sy_call_t *)freebsd32_sendfile, AUE_SENDFILE, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 393 = freebsd32_sendfile */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 394 = mac_syscall */
	{ compat11(AS(freebsd11_getfsstat_args),getfsstat), AUE_GETFSSTAT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 395 = freebsd11 getfsstat */
	{ compat11(AS(freebsd11_statfs_args),statfs), AUE_STATFS, NULL, 0, 0, 0, SY_THR_STATIC },	/* 396 = freebsd11 statfs */
	{ compat11(AS(freebsd11_fstatfs_args),fstatfs), AUE_FSTATFS, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 397 = freebsd11 fstatfs */
	{ compat11(AS(freebsd11_fhstatfs_args),fhstatfs), AUE_FHSTATFS, NULL, 0, 0, 0, SY_THR_STATIC },	/* 398 = freebsd11 fhstatfs */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 399 = nosys */
	{ AS(ksem_close_args), (sy_call_t *)lkmressys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },	/* 400 = ksem_close */
	{ AS(ksem_post_args), (sy_call_t *)lkmressys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },	/* 401 = ksem_post */
	{ AS(ksem_wait_args), (sy_call_t *)lkmressys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },	/* 402 = ksem_wait */
	{ AS(ksem_trywait_args), (sy_call_t *)lkmressys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },	/* 403 = ksem_trywait */
	{ AS(ksem_init_args), (sy_call_t *)lkmressys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },	/* 404 = ksem_init */
	{ AS(ksem_open_args), (sy_call_t *)lkmressys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },	/* 405 = ksem_open */
	{ AS(ksem_unlink_args), (sy_call_t *)lkmressys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },	/* 406 = ksem_unlink */
	{ AS(ksem_getvalue_args), (sy_call_t *)lkmressys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },	/* 407 = ksem_getvalue */
	{ AS(ksem_destroy_args), (sy_call_t *)lkmressys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },	/* 408 = ksem_destroy */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 409 = __mac_get_pid */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 410 = __mac_get_link */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 411 = __mac_set_link */
	{ AS(extattr_set_link_args), (sy_call_t *)sys_extattr_set_link, AUE_EXTATTR_SET_LINK, NULL, 0, 0, 0, SY_THR_STATIC },	/* 412 = extattr_set_link */
	{ AS(extattr_get_link_args), (sy_call_t *)sys_extattr_get_link, AUE_EXTATTR_GET_LINK, NULL, 0, 0, 0, SY_THR_STATIC },	/* 413 = extattr_get_link */
	{ AS(extattr_delete_link_args), (sy_call_t *)sys_extattr_delete_link, AUE_EXTATTR_DELETE_LINK, NULL, 0, 0, 0, SY_THR_STATIC },	/* 414 = extattr_delete_link */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 415 = __mac_execve */
	{ AS(freebsd32_sigaction_args), (sy_call_t *)freebsd32_sigaction, AUE_SIGACTION, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 416 = freebsd32_sigaction */
	{ AS(freebsd32_sigreturn_args), (sy_call_t *)freebsd32_sigreturn, AUE_SIGRETURN, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 417 = freebsd32_sigreturn */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 418 = __xstat */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 419 = __xfstat */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 420 = __xlstat */
	{ AS(freebsd32_getcontext_args), (sy_call_t *)freebsd32_getcontext, AUE_NULL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 421 = freebsd32_getcontext */
	{ AS(freebsd32_setcontext_args), (sy_call_t *)freebsd32_setcontext, AUE_NULL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 422 = freebsd32_setcontext */
	{ AS(freebsd32_swapcontext_args), (sy_call_t *)freebsd32_swapcontext, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 423 = freebsd32_swapcontext */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 424 = swapoff */
	{ AS(__acl_get_link_args), (sy_call_t *)sys___acl_get_link, AUE_ACL_GET_LINK, NULL, 0, 0, 0, SY_THR_STATIC },	/* 425 = __acl_get_link */
	{ AS(__acl_set_link_args), (sy_call_t *)sys___acl_set_link, AUE_ACL_SET_LINK, NULL, 0, 0, 0, SY_THR_STATIC },	/* 426 = __acl_set_link */
	{ AS(__acl_delete_link_args), (sy_call_t *)sys___acl_delete_link, AUE_ACL_DELETE_LINK, NULL, 0, 0, 0, SY_THR_STATIC },	/* 427 = __acl_delete_link */
	{ AS(__acl_aclcheck_link_args), (sy_call_t *)sys___acl_aclcheck_link, AUE_ACL_CHECK_LINK, NULL, 0, 0, 0, SY_THR_STATIC },	/* 428 = __acl_aclcheck_link */
	{ AS(sigwait_args), (sy_call_t *)sys_sigwait, AUE_SIGWAIT, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 429 = sigwait */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 430 = thr_create; */
	{ AS(thr_exit_args), (sy_call_t *)sys_thr_exit, AUE_THR_EXIT, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 431 = thr_exit */
	{ AS(thr_self_args), (sy_call_t *)sys_thr_self, AUE_NULL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 432 = thr_self */
	{ AS(thr_kill_args), (sy_call_t *)sys_thr_kill, AUE_THR_KILL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 433 = thr_kill */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 434 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 435 = nosys */
	{ AS(jail_attach_args), (sy_call_t *)sys_jail_attach, AUE_JAIL_ATTACH, NULL, 0, 0, 0, SY_THR_STATIC },	/* 436 = jail_attach */
	{ AS(extattr_list_fd_args), (sy_call_t *)sys_extattr_list_fd, AUE_EXTATTR_LIST_FD, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 437 = extattr_list_fd */
	{ AS(extattr_list_file_args), (sy_call_t *)sys_extattr_list_file, AUE_EXTATTR_LIST_FILE, NULL, 0, 0, 0, SY_THR_STATIC },	/* 438 = extattr_list_file */
	{ AS(extattr_list_link_args), (sy_call_t *)sys_extattr_list_link, AUE_EXTATTR_LIST_LINK, NULL, 0, 0, 0, SY_THR_STATIC },	/* 439 = extattr_list_link */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 440 = obsolete kse_switchin */
	{ AS(freebsd32_ksem_timedwait_args), (sy_call_t *)lkmressys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },	/* 441 = freebsd32_ksem_timedwait */
	{ AS(freebsd32_thr_suspend_args), (sy_call_t *)freebsd32_thr_suspend, AUE_NULL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 442 = freebsd32_thr_suspend */
	{ AS(thr_wake_args), (sy_call_t *)sys_thr_wake, AUE_NULL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 443 = thr_wake */
	{ AS(kldunloadf_args), (sy_call_t *)sys_kldunloadf, AUE_MODUNLOAD, NULL, 0, 0, 0, SY_THR_STATIC },	/* 444 = kldunloadf */
	{ AS(audit_args), (sy_call_t *)sys_audit, AUE_AUDIT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 445 = audit */
	{ AS(auditon_args), (sy_call_t *)sys_auditon, AUE_AUDITON, NULL, 0, 0, 0, SY_THR_STATIC },	/* 446 = auditon */
	{ AS(getauid_args), (sy_call_t *)sys_getauid, AUE_GETAUID, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 447 = getauid */
	{ AS(setauid_args), (sy_call_t *)sys_setauid, AUE_SETAUID, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 448 = setauid */
	{ AS(getaudit_args), (sy_call_t *)sys_getaudit, AUE_GETAUDIT, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 449 = getaudit */
	{ AS(setaudit_args), (sy_call_t *)sys_setaudit, AUE_SETAUDIT, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 450 = setaudit */
	{ AS(getaudit_addr_args), (sy_call_t *)sys_getaudit_addr, AUE_GETAUDIT_ADDR, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 451 = getaudit_addr */
	{ AS(setaudit_addr_args), (sy_call_t *)sys_setaudit_addr, AUE_SETAUDIT_ADDR, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 452 = setaudit_addr */
	{ AS(auditctl_args), (sy_call_t *)sys_auditctl, AUE_AUDITCTL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 453 = auditctl */
	{ AS(freebsd32__umtx_op_args), (sy_call_t *)freebsd32__umtx_op, AUE_NULL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 454 = freebsd32__umtx_op */
	{ AS(freebsd32_thr_new_args), (sy_call_t *)freebsd32_thr_new, AUE_THR_NEW, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 455 = freebsd32_thr_new */
	{ AS(freebsd32_sigqueue_args), (sy_call_t *)freebsd32_sigqueue, AUE_NULL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 456 = freebsd32_sigqueue */
	{ AS(freebsd32_kmq_open_args), (sy_call_t *)lkmressys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },	/* 457 = freebsd32_kmq_open */
	{ AS(freebsd32_kmq_setattr_args), (sy_call_t *)lkmressys, AUE_NULL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_ABSENT },	/* 458 = freebsd32_kmq_setattr */
	{ AS(freebsd32_kmq_timedreceive_args), (sy_call_t *)lkmressys, AUE_NULL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_ABSENT },	/* 459 = freebsd32_kmq_timedreceive */
	{ AS(freebsd32_kmq_timedsend_args), (sy_call_t *)lkmressys, AUE_NULL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_ABSENT },	/* 460 = freebsd32_kmq_timedsend */
	{ AS(freebsd32_kmq_notify_args), (sy_call_t *)lkmressys, AUE_NULL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_ABSENT },	/* 461 = freebsd32_kmq_notify */
	{ AS(kmq_unlink_args), (sy_call_t *)lkmressys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },	/* 462 = kmq_unlink */
	{ AS(abort2_args), (sy_call_t *)sys_abort2, AUE_NULL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 463 = abort2 */
	{ AS(thr_set_name_args), (sy_call_t *)sys_thr_set_name, AUE_NULL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 464 = thr_set_name */
	{ AS(freebsd32_aio_fsync_args), (sy_call_t *)freebsd32_aio_fsync, AUE_AIO_FSYNC, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 465 = freebsd32_aio_fsync */
	{ AS(rtprio_thread_args), (sy_call_t *)sys_rtprio_thread, AUE_RTPRIO, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 466 = rtprio_thread */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 467 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 468 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 469 = __getpath_fromfd */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 470 = __getpath_fromaddr */
	{ AS(sctp_peeloff_args), (sy_call_t *)lkmressys, AUE_NULL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_ABSENT },	/* 471 = sctp_peeloff */
	{ AS(sctp_generic_sendmsg_args), (sy_call_t *)lkmressys, AUE_NULL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_ABSENT },	/* 472 = sctp_generic_sendmsg */
	{ AS(freebsd32_sctp_generic_sendmsg_iov_args), (sy_call_t *)lkmressys, AUE_NULL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_ABSENT },	/* 473 = freebsd32_sctp_generic_sendmsg_iov */
	{ AS(freebsd32_sctp_generic_recvmsg_args), (sy_call_t *)lkmressys, AUE_NULL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_ABSENT },	/* 474 = freebsd32_sctp_generic_recvmsg */
#ifdef PAD64_REQUIRED
	{ AS(freebsd32_pread_args), (sy_call_t *)freebsd32_pread, AUE_PREAD, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 475 = freebsd32_pread */
	{ AS(freebsd32_pwrite_args), (sy_call_t *)freebsd32_pwrite, AUE_PWRITE, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 476 = freebsd32_pwrite */
	{ AS(freebsd32_mmap_args), (sy_call_t *)freebsd32_mmap, AUE_MMAP, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 477 = freebsd32_mmap */
	{ AS(freebsd32_lseek_args), (sy_call_t *)freebsd32_lseek, AUE_LSEEK, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 478 = freebsd32_lseek */
	{ AS(freebsd32_truncate_args), (sy_call_t *)freebsd32_truncate, AUE_TRUNCATE, NULL, 0, 0, 0, SY_THR_STATIC },	/* 479 = freebsd32_truncate */
	{ AS(freebsd32_ftruncate_args), (sy_call_t *)freebsd32_ftruncate, AUE_FTRUNCATE, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 480 = freebsd32_ftruncate */
#else
	{ AS(freebsd32_pread_args), (sy_call_t *)freebsd32_pread, AUE_PREAD, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 475 = freebsd32_pread */
	{ AS(freebsd32_pwrite_args), (sy_call_t *)freebsd32_pwrite, AUE_PWRITE, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 476 = freebsd32_pwrite */
	{ AS(freebsd32_mmap_args), (sy_call_t *)freebsd32_mmap, AUE_MMAP, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 477 = freebsd32_mmap */
	{ AS(freebsd32_lseek_args), (sy_call_t *)freebsd32_lseek, AUE_LSEEK, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 478 = freebsd32_lseek */
	{ AS(freebsd32_truncate_args), (sy_call_t *)freebsd32_truncate, AUE_TRUNCATE, NULL, 0, 0, 0, SY_THR_STATIC },	/* 479 = freebsd32_truncate */
	{ AS(freebsd32_ftruncate_args), (sy_call_t *)freebsd32_ftruncate, AUE_FTRUNCATE, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 480 = freebsd32_ftruncate */
#endif
	{ AS(thr_kill2_args), (sy_call_t *)sys_thr_kill2, AUE_THR_KILL2, NULL, 0, 0, 0, SY_THR_STATIC },	/* 481 = thr_kill2 */
	{ compat12(AS(freebsd12_shm_open_args),shm_open), AUE_SHMOPEN, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 482 = freebsd12 shm_open */
	{ AS(shm_unlink_args), (sy_call_t *)sys_shm_unlink, AUE_SHMUNLINK, NULL, 0, 0, 0, SY_THR_STATIC },	/* 483 = shm_unlink */
	{ AS(cpuset_args), (sy_call_t *)sys_cpuset, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 484 = cpuset */
#ifdef PAD64_REQUIRED
	{ AS(freebsd32_cpuset_setid_args), (sy_call_t *)freebsd32_cpuset_setid, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 485 = freebsd32_cpuset_setid */
#else
	{ AS(freebsd32_cpuset_setid_args), (sy_call_t *)freebsd32_cpuset_setid, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 485 = freebsd32_cpuset_setid */
#endif
	{ AS(freebsd32_cpuset_getid_args), (sy_call_t *)freebsd32_cpuset_getid, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 486 = freebsd32_cpuset_getid */
	{ AS(freebsd32_cpuset_getaffinity_args), (sy_call_t *)freebsd32_cpuset_getaffinity, AUE_NULL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 487 = freebsd32_cpuset_getaffinity */
	{ AS(freebsd32_cpuset_setaffinity_args), (sy_call_t *)freebsd32_cpuset_setaffinity, AUE_NULL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 488 = freebsd32_cpuset_setaffinity */
	{ AS(faccessat_args), (sy_call_t *)sys_faccessat, AUE_FACCESSAT, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 489 = faccessat */
	{ AS(fchmodat_args), (sy_call_t *)sys_fchmodat, AUE_FCHMODAT, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 490 = fchmodat */
	{ AS(fchownat_args), (sy_call_t *)sys_fchownat, AUE_FCHOWNAT, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 491 = fchownat */
	{ AS(freebsd32_fexecve_args), (sy_call_t *)freebsd32_fexecve, AUE_FEXECVE, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 492 = freebsd32_fexecve */
	{ compat11(AS(freebsd11_freebsd32_fstatat_args),freebsd32_fstatat), AUE_FSTATAT, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 493 = freebsd11 freebsd32_fstatat */
	{ AS(freebsd32_futimesat_args), (sy_call_t *)freebsd32_futimesat, AUE_FUTIMESAT, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 494 = freebsd32_futimesat */
	{ AS(linkat_args), (sy_call_t *)sys_linkat, AUE_LINKAT, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 495 = linkat */
	{ AS(mkdirat_args), (sy_call_t *)sys_mkdirat, AUE_MKDIRAT, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 496 = mkdirat */
	{ AS(mkfifoat_args), (sy_call_t *)sys_mkfifoat, AUE_MKFIFOAT, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 497 = mkfifoat */
	{ compat11(AS(freebsd11_mknodat_args),mknodat), AUE_MKNODAT, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 498 = freebsd11 mknodat */
	{ AS(openat_args), (sy_call_t *)sys_openat, AUE_OPENAT_RWTC, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 499 = openat */
	{ AS(readlinkat_args), (sy_call_t *)sys_readlinkat, AUE_READLINKAT, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 500 = readlinkat */
	{ AS(renameat_args), (sy_call_t *)sys_renameat, AUE_RENAMEAT, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 501 = renameat */
	{ AS(symlinkat_args), (sy_call_t *)sys_symlinkat, AUE_SYMLINKAT, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 502 = symlinkat */
	{ AS(unlinkat_args), (sy_call_t *)sys_unlinkat, AUE_UNLINKAT, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 503 = unlinkat */
	{ AS(posix_openpt_args), (sy_call_t *)sys_posix_openpt, AUE_POSIX_OPENPT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 504 = posix_openpt */
	{ AS(gssd_syscall_args), (sy_call_t *)lkmressys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },	/* 505 = gssd_syscall */
	{ AS(freebsd32_jail_get_args), (sy_call_t *)freebsd32_jail_get, AUE_JAIL_GET, NULL, 0, 0, 0, SY_THR_STATIC },	/* 506 = freebsd32_jail_get */
	{ AS(freebsd32_jail_set_args), (sy_call_t *)freebsd32_jail_set, AUE_JAIL_SET, NULL, 0, 0, 0, SY_THR_STATIC },	/* 507 = freebsd32_jail_set */
	{ AS(jail_remove_args), (sy_call_t *)sys_jail_remove, AUE_JAIL_REMOVE, NULL, 0, 0, 0, SY_THR_STATIC },	/* 508 = jail_remove */
	{ compat12(AS(freebsd12_closefrom_args),closefrom), AUE_CLOSEFROM, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 509 = freebsd12 closefrom */
	{ AS(freebsd32_semctl_args), (sy_call_t *)lkmressys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },	/* 510 = freebsd32_semctl */
	{ AS(freebsd32_msgctl_args), (sy_call_t *)lkmressys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },	/* 511 = freebsd32_msgctl */
	{ AS(freebsd32_shmctl_args), (sy_call_t *)lkmressys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },	/* 512 = freebsd32_shmctl */
	{ AS(lpathconf_args), (sy_call_t *)sys_lpathconf, AUE_LPATHCONF, NULL, 0, 0, 0, SY_THR_STATIC },	/* 513 = lpathconf */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 514 = obsolete cap_new */
	{ AS(__cap_rights_get_args), (sy_call_t *)sys___cap_rights_get, AUE_CAP_RIGHTS_GET, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 515 = __cap_rights_get */
	{ 0, (sy_call_t *)sys_cap_enter, AUE_CAP_ENTER, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 516 = cap_enter */
	{ AS(cap_getmode_args), (sy_call_t *)sys_cap_getmode, AUE_CAP_GETMODE, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 517 = cap_getmode */
	{ AS(pdfork_args), (sy_call_t *)sys_pdfork, AUE_PDFORK, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 518 = pdfork */
	{ AS(pdkill_args), (sy_call_t *)sys_pdkill, AUE_PDKILL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 519 = pdkill */
	{ AS(pdgetpid_args), (sy_call_t *)sys_pdgetpid, AUE_PDGETPID, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 520 = pdgetpid */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 521 = pdwait4 */
	{ AS(freebsd32_pselect_args), (sy_call_t *)freebsd32_pselect, AUE_SELECT, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 522 = freebsd32_pselect */
	{ AS(getloginclass_args), (sy_call_t *)sys_getloginclass, AUE_GETLOGINCLASS, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 523 = getloginclass */
	{ AS(setloginclass_args), (sy_call_t *)sys_setloginclass, AUE_SETLOGINCLASS, NULL, 0, 0, 0, SY_THR_STATIC },	/* 524 = setloginclass */
	{ AS(rctl_get_racct_args), (sy_call_t *)sys_rctl_get_racct, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 525 = rctl_get_racct */
	{ AS(rctl_get_rules_args), (sy_call_t *)sys_rctl_get_rules, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 526 = rctl_get_rules */
	{ AS(rctl_get_limits_args), (sy_call_t *)sys_rctl_get_limits, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 527 = rctl_get_limits */
	{ AS(rctl_add_rule_args), (sy_call_t *)sys_rctl_add_rule, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 528 = rctl_add_rule */
	{ AS(rctl_remove_rule_args), (sy_call_t *)sys_rctl_remove_rule, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 529 = rctl_remove_rule */
#ifdef PAD64_REQUIRED
	{ AS(freebsd32_posix_fallocate_args), (sy_call_t *)freebsd32_posix_fallocate, AUE_POSIX_FALLOCATE, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 530 = freebsd32_posix_fallocate */
	{ AS(freebsd32_posix_fadvise_args), (sy_call_t *)freebsd32_posix_fadvise, AUE_POSIX_FADVISE, NULL, 0, 0, 0, SY_THR_STATIC },	/* 531 = freebsd32_posix_fadvise */
	{ AS(freebsd32_wait6_args), (sy_call_t *)freebsd32_wait6, AUE_WAIT6, NULL, 0, 0, 0, SY_THR_STATIC },	/* 532 = freebsd32_wait6 */
#else
	{ AS(freebsd32_posix_fallocate_args), (sy_call_t *)freebsd32_posix_fallocate, AUE_POSIX_FALLOCATE, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 530 = freebsd32_posix_fallocate */
	{ AS(freebsd32_posix_fadvise_args), (sy_call_t *)freebsd32_posix_fadvise, AUE_POSIX_FADVISE, NULL, 0, 0, 0, SY_THR_STATIC },	/* 531 = freebsd32_posix_fadvise */
	{ AS(freebsd32_wait6_args), (sy_call_t *)freebsd32_wait6, AUE_WAIT6, NULL, 0, 0, 0, SY_THR_STATIC },	/* 532 = freebsd32_wait6 */
#endif
	{ AS(cap_rights_limit_args), (sy_call_t *)sys_cap_rights_limit, AUE_CAP_RIGHTS_LIMIT, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 533 = cap_rights_limit */
	{ AS(freebsd32_cap_ioctls_limit_args), (sy_call_t *)freebsd32_cap_ioctls_limit, AUE_CAP_IOCTLS_LIMIT, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 534 = freebsd32_cap_ioctls_limit */
	{ AS(freebsd32_cap_ioctls_get_args), (sy_call_t *)freebsd32_cap_ioctls_get, AUE_CAP_IOCTLS_GET, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 535 = freebsd32_cap_ioctls_get */
	{ AS(cap_fcntls_limit_args), (sy_call_t *)sys_cap_fcntls_limit, AUE_CAP_FCNTLS_LIMIT, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 536 = cap_fcntls_limit */
	{ AS(cap_fcntls_get_args), (sy_call_t *)sys_cap_fcntls_get, AUE_CAP_FCNTLS_GET, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 537 = cap_fcntls_get */
	{ AS(bindat_args), (sy_call_t *)sys_bindat, AUE_BINDAT, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 538 = bindat */
	{ AS(connectat_args), (sy_call_t *)sys_connectat, AUE_CONNECTAT, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 539 = connectat */
	{ AS(chflagsat_args), (sy_call_t *)sys_chflagsat, AUE_CHFLAGSAT, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 540 = chflagsat */
	{ AS(accept4_args), (sy_call_t *)sys_accept4, AUE_ACCEPT, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 541 = accept4 */
	{ AS(pipe2_args), (sy_call_t *)sys_pipe2, AUE_PIPE, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 542 = pipe2 */
	{ AS(freebsd32_aio_mlock_args), (sy_call_t *)freebsd32_aio_mlock, AUE_AIO_MLOCK, NULL, 0, 0, 0, SY_THR_STATIC },	/* 543 = freebsd32_aio_mlock */
#ifdef PAD64_REQUIRED
	{ AS(freebsd32_procctl_args), (sy_call_t *)freebsd32_procctl, AUE_PROCCTL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 544 = freebsd32_procctl */
#else
	{ AS(freebsd32_procctl_args), (sy_call_t *)freebsd32_procctl, AUE_PROCCTL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 544 = freebsd32_procctl */
#endif
	{ AS(freebsd32_ppoll_args), (sy_call_t *)freebsd32_ppoll, AUE_POLL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 545 = freebsd32_ppoll */
	{ AS(freebsd32_futimens_args), (sy_call_t *)freebsd32_futimens, AUE_FUTIMES, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 546 = freebsd32_futimens */
	{ AS(freebsd32_utimensat_args), (sy_call_t *)freebsd32_utimensat, AUE_FUTIMESAT, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 547 = freebsd32_utimensat */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 548 = obsolete numa_getaffinity */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 549 = obsolete numa_setaffinity */
	{ AS(fdatasync_args), (sy_call_t *)sys_fdatasync, AUE_FSYNC, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 550 = fdatasync */
	{ AS(freebsd32_fstat_args), (sy_call_t *)freebsd32_fstat, AUE_FSTAT, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 551 = freebsd32_fstat */
	{ AS(freebsd32_fstatat_args), (sy_call_t *)freebsd32_fstatat, AUE_FSTATAT, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 552 = freebsd32_fstatat */
	{ AS(freebsd32_fhstat_args), (sy_call_t *)freebsd32_fhstat, AUE_FHSTAT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 553 = freebsd32_fhstat */
	{ AS(getdirentries_args), (sy_call_t *)sys_getdirentries, AUE_GETDIRENTRIES, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 554 = getdirentries */
	{ AS(statfs_args), (sy_call_t *)sys_statfs, AUE_STATFS, NULL, 0, 0, 0, SY_THR_STATIC },	/* 555 = statfs */
	{ AS(fstatfs_args), (sy_call_t *)sys_fstatfs, AUE_FSTATFS, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 556 = fstatfs */
	{ AS(getfsstat_args), (sy_call_t *)sys_getfsstat, AUE_GETFSSTAT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 557 = getfsstat */
	{ AS(fhstatfs_args), (sy_call_t *)sys_fhstatfs, AUE_FHSTATFS, NULL, 0, 0, 0, SY_THR_STATIC },	/* 558 = fhstatfs */
#ifdef PAD64_REQUIRED
	{ AS(freebsd32_mknodat_args), (sy_call_t *)freebsd32_mknodat, AUE_MKNODAT, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 559 = freebsd32_mknodat */
#else
	{ AS(freebsd32_mknodat_args), (sy_call_t *)freebsd32_mknodat, AUE_MKNODAT, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 559 = freebsd32_mknodat */
#endif
	{ AS(freebsd32_kevent_args), (sy_call_t *)freebsd32_kevent, AUE_KEVENT, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 560 = freebsd32_kevent */
	{ AS(freebsd32_cpuset_getdomain_args), (sy_call_t *)freebsd32_cpuset_getdomain, AUE_NULL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 561 = freebsd32_cpuset_getdomain */
	{ AS(freebsd32_cpuset_setdomain_args), (sy_call_t *)freebsd32_cpuset_setdomain, AUE_NULL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 562 = freebsd32_cpuset_setdomain */
	{ AS(getrandom_args), (sy_call_t *)sys_getrandom, AUE_NULL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 563 = getrandom */
	{ AS(getfhat_args), (sy_call_t *)sys_getfhat, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 564 = getfhat */
	{ AS(fhlink_args), (sy_call_t *)sys_fhlink, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 565 = fhlink */
	{ AS(fhlinkat_args), (sy_call_t *)sys_fhlinkat, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 566 = fhlinkat */
	{ AS(fhreadlink_args), (sy_call_t *)sys_fhreadlink, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 567 = fhreadlink */
	{ AS(funlinkat_args), (sy_call_t *)sys_funlinkat, AUE_UNLINKAT, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 568 = funlinkat */
	{ AS(copy_file_range_args), (sy_call_t *)sys_copy_file_range, AUE_NULL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 569 = copy_file_range */
	{ AS(freebsd32___sysctlbyname_args), (sy_call_t *)freebsd32___sysctlbyname, AUE_SYSCTL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 570 = freebsd32___sysctlbyname */
	{ AS(shm_open2_args), (sy_call_t *)sys_shm_open2, AUE_SHMOPEN, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 571 = shm_open2 */
	{ AS(shm_rename_args), (sy_call_t *)sys_shm_rename, AUE_SHMRENAME, NULL, 0, 0, 0, SY_THR_STATIC },	/* 572 = shm_rename */
	{ AS(sigfastblock_args), (sy_call_t *)sys_sigfastblock, AUE_NULL, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 573 = sigfastblock */
	{ AS(__realpathat_args), (sy_call_t *)sys___realpathat, AUE_REALPATHAT, NULL, 0, 0, 0, SY_THR_STATIC },	/* 574 = __realpathat */
	{ AS(close_range_args), (sy_call_t *)sys_close_range, AUE_CLOSERANGE, NULL, 0, 0, SYF_CAPENABLED, SY_THR_STATIC },	/* 575 = close_range */
	{ AS(rpctls_syscall_args), (sy_call_t *)lkmressys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },	/* 576 = rpctls_syscall */
};
