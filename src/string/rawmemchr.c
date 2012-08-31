#define _GNU_SOURCE
#include <string.h>
#include "libc.h"

void *rawmemchr(const void *s, int c)
{
	return memchr(s, c, (size_t) -1);
}

weak_alias(rawmemchr, __rawmemchr);
