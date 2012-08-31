#include "syscall.h"
#include <sys/capability.h>

int capset(cap_user_header_t a, cap_user_data_t b)
{
	return syscall(SYS_capset, a, b);
}

int capget(cap_user_header_t a, cap_user_data_t b)
{
	return syscall(SYS_capget, a, b);
}
