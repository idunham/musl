#include <math.h>
#include "libc.h"

int isnanl(x){
	return isnan(x);
}

weak_alias(isnanl,isnan);
weak_alias(isnanl,isnanf);
