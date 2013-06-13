#include <stdio.h>
#include <netinet/ether.h>

static char x[18];

char *ether_ntoa_r (const struct ether_addr *p_a, char *x) {
	char *y;
	y = x;
	for (int ii = 0; ii < 6; ii++) {
		x += sprintf (x, ii == 0 ? "%.2X" : ":%.2X", p_a -> ether_addr_octet[ii]);
	}
	return y;
}

char *ether_ntoa (const struct ether_addr *p_a) {
	return ether_ntoa_r (p_a, x);
}
