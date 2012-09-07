#include <string.h>
#include "libc.h"

char *__stpcpy(char *, const char *);

char *strcpy(char *restrict dest, const char *restrict src)
{
#if 1
	__stpcpy(dest, src);
	return dest;
#else
	const unsigned char *s = src;
	unsigned char *d = dest;
	while ((*d++ = *s++));
	return dest;
#endif
}

/* NOTE: __strcpy_chk actually takes a third argument, which we ignore; it is a
 * matter of ABI whether this alias is therefore safe or not */
weak_alias(strcpy, __strcpy_chk);
