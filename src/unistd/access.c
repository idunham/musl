#include <unistd.h>
#include "syscall.h"

int access(const char *filename, int amode)
{
	return syscall(SYS_access, filename, amode);
}
/*
 * For glibc compatability.
 * Not really correct, since they should check effective UID instead.
 */

weak_alias(access,euidaccess);
weak_alias(access,eaccess);
