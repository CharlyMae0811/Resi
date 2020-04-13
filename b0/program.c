#include <stdio.h>
#include <stdint.h>

int
main(void)
{
	int64_t p = 1,
		l = 2,
		e = 5,
		a = 61,
		m = 251,
		n = 3659,
		o = 271173410,
		t = 1479296389,
		x = {t*o*l*l*e, p*a*l*m*e*n};
	puts((char*)x);
	return 0;
}
