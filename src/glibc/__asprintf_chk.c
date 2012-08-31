#define _GNU_SOURCE
#include <stdarg.h>
#include <stdio.h>

int __asprintf_chk(char **strp, int flag, const char *format, ...)
{
	int ret;
	va_list ap;
	va_start(ap, format);
	ret = vasprintf(strp, format, ap);
	va_end(ap);
	return ret;
}
