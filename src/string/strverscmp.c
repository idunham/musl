#define _GNU_SOURCE
#include <ctype.h>
#include <string.h>

int strverscmp(const char *l, const char *r)
{
	int haszero=1;
	while (*l && *r && l[0]==r[0]){
		if (l[0]=='0'){
			if (haszero==1) {
				haszero=0;
			}
		} else if (isdigit(l[0])) {
			if (haszero==1) {
				haszero=2;
			}
		} else {
			haszero=1;
		}
		l++; r++;
	}
	if (haszero==1 && (l[0]=='0' || r[0]=='0')) {
		haszero=0;
	}
	if ((isdigit(l[0]) && isdigit(r[0]) ) && haszero) {
		int lenl=0, lenr=0, firstl=l[0], firstr=r[0];
		while (isdigit(l++[0]) ) {
			lenl++;
		}
		while (isdigit(r++[0]) ) {
			lenr++;
		}
		if (lenl==lenr) {
			return (firstl -  firstr);
		} else {
			return (lenl - lenr);
		}
	} else {
		return (l[0] -  r[0]);
	}
}
