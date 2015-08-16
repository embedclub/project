/*htoi: convert hexadecimal string to integer*/

#include <stdio.h>
#include <string.h>
//#include <stdlib.h>

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	return (x & ~(~(~0 << n)  << (p+1-n)) | 
		(y & ~(~0 << n)) << (p+1-n));
}


main()
{
	unsigned x = 1024;
	unsigned y = 1234;
	//char s[20];
	//int xb;
	printf(" unsigned x = 0x%x \n", x);
	
	printf(" unsigned y = 0x%x \n", y);

	printf("the modified number is: 0x%x\n", setbits(x,7, 4, y));
}

