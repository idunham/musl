#include <stdarg.h>
#include <stdio.h>

int __fprintf_chk(FILE *stream, int flag, const char *format, ...)
{
	int ret;
	va_list ap;
	va_start(ap, format);
	ret = vfprintf(stream, format, ap);
	va_end(ap);
	return ret;
}
