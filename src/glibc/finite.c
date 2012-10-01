#include <math.h>
#include "libc.h"

int finite(x){
	return isfinite(x);
}
weak_alias(finite,finitel);
weak_alias(finite,__finitel);
weak_alias(finite,finitef);
