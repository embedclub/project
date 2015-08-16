
// atoi: convert string s to a int number
#include <stdio.h>
#include <string.h>

int atoi(char s[])
{
	int i, n;

	n = 0;
	for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i) {
		n = 10 * n + (s[i] - '0');
		printf("After %d bit ,the total number is: %d\n", i, n);
	}
	return n;
}

main()
{
	int sum;
	char s[30]; //="12345";
	gets(s);
	sum = atoi(s);
	printf("the string is: %s\n", s);
	printf("the int numer is: %d\n", sum);
}
