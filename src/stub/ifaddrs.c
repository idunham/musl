#include <errno.h>

/* 
 * A proper implementation of these functions requires the TAILQ* macros,
 * which should be defined in <sys/queue.h>.
 * getifaddrs should return a TAILQ-type linked list of these structs:
 * (copied verbatim from man 3 getifaddrs)
 */ 
/*
struct ifaddrs {
	struct ifaddrs	*ifa_next;
	char		*ifa_name;
	unsigned int	 ifa_flags;
	struct sockaddr	*ifa_addr;
	struct sockaddr	*ifa_netmask;
	union {
		struct sockaddr *ifu_broadaddr;
		struct sockaddr *ifu_dstaddr;
	} ifa_ifu;
	#define	ifa_broadaddr ifa_ifu.ifu_broadaddr
	#define	ifa_dstaddr   ifa_ifu.ifu_dstaddr
	void		*ifa_data;
};
*/
int getifaddrs (*ifp)
{
	errno = EACCES;
	return -1;
}

void freeifaddrs (*ifa)
{
}
