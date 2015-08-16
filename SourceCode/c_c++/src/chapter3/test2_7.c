/*rightrot: rotate x to the right by n positions*/

#include <stdio.h>
#include <string.h>
//#include <stdlib.h>

int wordlength(void);

//逐位实现右移
unsigned rightrot1(unsigned x, int n)
{
	int rbit;

	while (n-- > 0) {
		rbit = (x & 1) << (wordlength() -1);
		x = x >> 1;
		x = x | rbit;
	}
	return x;
}

//整段实现右移
unsigned rightrot2(unsigned x, int n)
{
	unsigned rbits;

	if ((n = n % wordlength()) > 0) {
		rbits = ~(~0 << n) & x;
		rbits = rbits << (wordlength() - n);
		x = x >> n;
		x = x | rbits;
	}
	return x;
}


main()
{
	unsigned x;
	int n;
	printf(" Input unsigned x, int n :\n");
	
	scanf("%u%d", &x, &n);

	printf("the modified number1 is: 0x%x\n", rightrot1(x, n));
	printf("the modified number2 is: 0x%x\n", rightrot2(x, n));
}

/* wordlength: computes word length of the machine */
int wordlength(void)
{
	int i;
	unsigned v = (unsigned) ~0;

	for (i =1; (v = v >> 1) > 0; i++)
		;
	return i;
}
