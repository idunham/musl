#include <stdlib.h>
#include <string.h>
#include <netinet/ether.h>

static struct ether_addr a;

struct ether_addr *ether_aton_r (const char *x, struct ether_addr *p_a) {
	struct ether_addr a;
	for (int ii = 0; ii < 6; ii++) {
		unsigned long int n;
		if (ii != 0) {
			if (x[0] != ':') return 0; /* bad format */
			else x++;
		}
		{
			char *y;
			n = strtoul (x, &y, 16);
			x = y;
		}
		if (n > 0xFF) return 0; /* bad byte */
		a.ether_addr_octet[ii] = n;
	}
	if (x[0] != 0) return 0; /* bad format */
	memmove (p_a, &a, sizeof (struct ether_addr));
	return p_a;
}

struct ether_addr *ether_aton (const char *x) {
	return ether_aton_r (x, &a);
}
