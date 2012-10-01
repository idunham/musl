#include "libc.h"
#include <math.h>

int __isinf(int x) {
	return isinf(x);
}
weak_alias(__isinf,isinf);
weak_alias(__isinf,isinfl);
weak_alias(__isinf,__isinfl);

