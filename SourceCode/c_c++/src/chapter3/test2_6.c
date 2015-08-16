/*invert: invert the n bits of x that begin at position p*/

#include <stdio.h>
#include <string.h>
//#include <stdlib.h>

unsigned invert(unsigned x, int p, int n)
{
	return (x ^ (~(~0 << n)  << (p+1-n)) );
}


main()
{
	unsigned x;
	int p, n;
	printf(" Input unsigned x, int p, int n :\n");
	
	scanf("%u%d%d", &x, &p, &n);

	printf("the modified number is: 0x%x\n", invert(x,p, n));
}

