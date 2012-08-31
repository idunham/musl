/* no prototype for this function is provided, it is solely for ABI
 * compatibility */
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

void error(int status, int errnum, const char *format, ...)
{
	va_list ap;
	fflush(stdout);
	va_start(ap, format);
	vfprintf(stderr, format, ap);
	va_end(ap);
	if (errnum) fprintf(stderr, ": %s\n", strerror(errnum));
	else fputs("\n", stderr);
}
