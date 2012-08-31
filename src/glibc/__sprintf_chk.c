#include <stdarg.h>
#include <stdio.h>

int __sprintf_chk(char *str, int flag, size_t strlen, const char *format, ...)
{
	int ret;
	va_list ap;
	va_start(ap, format);
	ret = vsnprintf(str, strlen, format, ap);
	va_end(ap);
	return ret;
}
