#include <stdarg.h>
#include <stdio.h>

int __snprintf_chk(char *str, size_t maxlen, int flag, size_t strlen, const char *format, ...)
{
	int ret;
	va_list ap;
	va_start(ap, format);
	ret = vsnprintf(str, maxlen, format, ap);
	va_end(ap);
	return ret;
}
