/* no prototype is provided, this function solely for ABI compatibility */
#define _POSIX_C_SOURCE 200112L
#include <signal.h>

int sigsetmask(int mask)
{
	return 0;
}
