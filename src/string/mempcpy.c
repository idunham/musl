#define _GNU_SOURCE
#include <string.h>
#include "libc.h"

void *mempcpy(void *dest, const void *src, size_t n)
{
	return (char *)memcpy(dest, src, n) + n;
}

/* NOTE: __mempcpy_chk actually takes a fourth argument, which we ignore; it is
 * a matter of ABI whether this alias is therefore safe or not */
weak_alias(mempcpy, __mempcpy_chk);
