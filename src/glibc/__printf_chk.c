#include <stdarg.h>
#include <stdio.h>

int __printf_chk(int flag, const char *format, ...)
{
	int ret;
	va_list ap;
	va_start(ap, format);
	ret = vprintf(format, ap);
	va_end(ap);
	return ret;
}
