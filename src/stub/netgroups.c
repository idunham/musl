/* stub for innetgr */
#define _GNU_SOURCE
#include <netdb.h>

int setnetgrent(const char *netgroup)
{
	return 0;
}

void endnetgrent(void)
{

}

int getnetgrent(char **host, char **user, char **domain)
{
	return 0;
}

int getnetgrent_r(char **host, char **user, char **domain, char *buf, int buflen)
{
	return 0;
}

int innetgr(const char *netgroup, const char *host, 
	const char *user, const char *domain) 
{
	return 0;
}
