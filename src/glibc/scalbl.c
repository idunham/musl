#include <math.h>

long double scalbl(long double x, double exp){
	return scalblnl(x, (int)(x));
}

