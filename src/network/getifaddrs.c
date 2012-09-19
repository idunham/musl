/*
 * Copyright (c) 1995, 1999
 *	Berkeley Software Design, Inc.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * THIS SOFTWARE IS PROVIDED BY Berkeley Software Design, Inc. ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL Berkeley Software Design, Inc. BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	BSDI getifaddrs.c,v 2.12 2000/02/23 14:51:59 dab Exp
 */
/*
 * NOTE: SIOCGIFCONF case is not LP64 friendly.  it also does not perform
 * try-and-error for region size.
 */

#define _BSD_SOURCE
#include <sys/types.h>
#include <sys/types.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <net/if.h>

#include <ifaddrs.h>
#include <stdlib.h>
#include <string.h>

#if !defined(AF_LINK)
#define	SA_LEN(sa)	sizeof(struct sockaddr)
#endif

#if !defined(SA_LEN)
#define	SA_LEN(sa)	sizeof(struct sockaddr)
#endif

#define	SALIGN	(sizeof(long) - 1)
#define	SA_RLEN(sa)	(sizeof(struct sockaddr) ? ((sizeof(struct sockaddr) + SALIGN) & ~SALIGN) : (SALIGN + 1))

#ifndef	ALIGNBYTES
/*
 * On systems with a routing socket, ALIGNBYTES should match the value
 * that the kernel uses when building the messages.
 */
#define	ALIGNBYTES	XXX
#endif
#ifndef	ALIGN
#define	ALIGN(p)	(((u_long)(p) + ALIGNBYTES) &~ ALIGNBYTES)
#endif

int
getifaddrs(struct ifaddrs **pif)
{
	int icnt = 1;
	int dcnt = 0;
	int ncnt = 0;
	struct ifaddrs *ifa, *ift;
	char buf[1024];
	int m, sock;
	struct ifconf ifc;
	struct ifreq *ifr;
	struct ifreq *lifr;
	int i;
	size_t len, alen;
	char *data;
	char *names;

	ifc.ifc_buf = buf;
	ifc.ifc_len = sizeof(buf);

	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		return (-1);
	i =  ioctl(sock, SIOCGIFCONF, (char *)&ifc);
	close(sock);
	if (i < 0)
		return (-1);

	ifr = ifc.ifc_req;
	lifr = (struct ifreq *)&ifc.ifc_buf[ifc.ifc_len];

	while (ifr < lifr) {
		struct sockaddr *sa;

		sa = &ifr->ifr_addr;
		++icnt;
		dcnt += SA_RLEN(sa);
		ncnt += sizeof(ifr->ifr_name) + 1;
		
		if (SA_LEN(sa) < sizeof(*sa))
			ifr = (struct ifreq *)(((char *)sa) + sizeof(*sa));
		else
			ifr = (struct ifreq *)(((char *)sa) + SA_LEN(sa));
	}

	if (icnt + dcnt + ncnt == 1) {
		*pif = NULL;
		free(buf);
		return (0);
	}
	data = malloc(sizeof(struct ifaddrs) * icnt + dcnt + ncnt);
	if (data == NULL) {
		free(buf);
		return(-1);
	}

	ifa = (struct ifaddrs *)(void *)data;
	data += sizeof(struct ifaddrs) * icnt;
	names = data + dcnt;

	memset(ifa, 0, sizeof(struct ifaddrs) * icnt);
	ift = ifa;

	ifr = ifc.ifc_req;
	lifr = (struct ifreq *)&ifc.ifc_buf[ifc.ifc_len];

	while (ifr < lifr) {
		struct sockaddr *sa;

		ift->ifa_name = names;
		names[sizeof(ifr->ifr_name)] = 0;
		strncpy(names, ifr->ifr_name, sizeof(ifr->ifr_name));
		while (*names++)
			;

		ift->ifa_addr = (struct sockaddr *)data;
		sa = &ifr->ifr_addr;
		memcpy(data, sa, SA_LEN(sa));
		data += SA_RLEN(sa);
		
		ifr = (struct ifreq *)(((char *)sa) + SA_LEN(sa));
		ift = (ift->ifa_next = ift + 1);
	}
	if (--ift >= ifa) {
		ift->ifa_next = NULL;
		*pif = ifa;
	} else {
		*pif = NULL;
		free(ifa);
	}
	return (0);
}

void
freeifaddrs(struct ifaddrs *ifp)
{

	free(ifp);
}
