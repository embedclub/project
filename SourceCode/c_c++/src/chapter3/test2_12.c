/*itoa: conver and save the digital n to a string  s[]*/

#include <stdio.h>
#include <string.h>
//#include <stdlib.h>

void reverse(char s[]);

void itoa(int n, char s[], int w)
{
	int i, sign;

	if ((sign = n) < 0)
		n = -n;
	i = 0;
	do {
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);

	if (sign < 0)
		s[i++] = '-';

	while (i < w)
		s[i++] = ' ';
	s[i] = '\0';
	reverse(s);
}

main()
{
	int n, w;
	char s[30];
		
	printf("Please input a digital and width n: \n");
	scanf("%d%d", &n, &w);

	itoa(n, s, w);	
	
	printf("th digital %d convert a string is : %s\n", n, s);
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