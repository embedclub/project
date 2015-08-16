/*itob: convert n to characters in s - base b*/

#include <stdio.h>
#include <string.h>
//#include <stdlib.h>

void reverse(char s[]);

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

main()
{
	int n, b;
	char s[30];
		
	printf("Please input a digital n and a base b: \n");
	scanf("%d%d", &n,&b);

	itob(n, s, b);	
	
	printf("th digital %d convert a base %d string is : %s\n", n, b, s);
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

