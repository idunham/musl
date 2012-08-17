/*
 * vm86plus/vm86old support.
 * vm86old is the original vm86, as provided by libc5, klibc, & glibc <2.3.3
 * vm86(plus) is the new syscall; glibc 2.3.4 + calls this vm86, and renames
 * vm86 as originally implemented to vm86old.
 * The question is thus which to call vm86.
 */
#include "syscall.h"

#ifdef SYS_vm86old
struct vm86_struct;

int vm86old(struct vm86_struct *info);
{
	return syscall(SYS_vm86old, info);
}
#endif

#ifdef SYS_vm86
struct vm86plus_struct;

int vm86(unsigned long fn, struct vm86plus_struct *v86);
{
	return syscall(SYS_vm86, fn, v86);
}
#endif
