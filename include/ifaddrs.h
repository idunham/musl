#ifndef _IFADDRS_H
#define _IFADDRS_H 1

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

#ifdef __cplusplus
extern "C" {
#endif

int getifaddrs(struct ifaddrs **);

void freeifaddrs(struct ifaddrs *);

#ifdef __cpluplus
}
#endif

#endif
