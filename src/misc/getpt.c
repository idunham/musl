/* No prototype is provided. This function is solely for ABI compatibility. */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int getpt(void)
{
	return open("/dev/ptmx", O_RDWR | O_NOCTTY);
}
