/*bit operators*/

#include <stdio.h>
#include <string.h>
//#include <stdlib.h>

void reverse(char s[]);
void itob(int n, char s[], int b);

void setbit(unsigned *x, int n)
{
	*x |= 1 << n;
	//printf(" After setbit  x = 0x%x \n", x);
}

void clearbit(unsigned *x, int n)
{
	*x &= ~(1 << n);
	//printf(" After clearbit  x = 0x%x \n", x);
}

int getbit(unsigned x, int n)
{
	if (( x >> n)  & 0x1)
		return 1;
	else
		return 0;
}

int bitcount(unsigned x)
{
	int b;
	for (b = 0; x != 0; x >>= 1)
		if (x & 0x1)
			b++;
	return b;
}


main()
{
	unsigned x;
	int n;
	char s[30];
	char t[30];
	
	printf(" Please input unsigned x and int n:\n");
	
	scanf("%x%d", &x,&n);

	setbit(&x, n);
	itob(x, s, 2);
	printf("After setbit %d, the digital is: %sb\n", n, s);
	printf("get the bit  %d, the value is: %d\n", n, getbit(x, n));
	
	clearbit(&x, n);
	itob(x, t, 2);
	printf("After clearbit %d, the digital is: %sb\n", n, t);

	printf("get the bit  %d, the value is: %d\n", n, getbit(x, n));
	
	printf("get the bit count is: %d\n", bitcount(x));
}

void itob(int n, char s[], int b)
{
	int i, j, sign;
	
	if ((sign = n) < 0)
		n = -n;
	i = 0;
	do {
		j = n % b;
		s[i++] = (j <= 9) ? j+'0' : j+'A'-10;
	} while ((n /= b ) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

void reverse(char s[])
{
	int i, j;
	char temp;
	i = 0;
	while (s[i] != '\0')
		++i;
	--i;
	if (s[i] == '\n')
		--i;
	j = 0;
	while (j < i) {
		temp = s[j];
		s[j] = s[i];
		s[i] = temp;
		--i;
		++j;
	}
}


