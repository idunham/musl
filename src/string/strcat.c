#include <string.h>
#include "libc.h"

char *strcat(char *dest, const char *src)
{
	strcpy(dest + strlen(dest), src);
	return dest;
}

/* NOTE: __strcat_chk actually takes a third argument, which we ignore; it is a
 * matter of ABI whether this alias is therefore safe or not */
weak_alias(strcat, __strcat_chk);
