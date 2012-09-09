#include <utmpx.h>
#include <stddef.h>
#include "libc.h"

void endutxent(void)
{
}

void setutxent(void)
{
}

struct utmpx *getutxent(void)
{
	return NULL;
}

struct utmpx *getutxid(const struct utmpx *ut)
{
	return NULL;
}

struct utmpx *getutxline(const struct utmpx *ut)
{
	return NULL;
}

struct utmpx *pututxline(const struct utmpx *ut)
{
	return NULL;
}

void updwtmpx(const char *f, const struct utmpx *u)
{
}

void logwtmp(const char *l, const char *n, const char *h)
{
}

weak_alias(endutxent, endutent);
weak_alias(setutxent, setutent);
weak_alias(getutxent, getutent);
weak_alias(getutxid, getutid);
weak_alias(getutxline, getutline);
weak_alias(pututxline, pututline);
weak_alias(updwtmpx, updwtmp);
