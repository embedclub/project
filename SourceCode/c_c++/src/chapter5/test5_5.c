#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*atoi: convert s to integer; pointer version*/
int atoi(char *s)
{
	int n, sign;

	for ( ; isspace(*s); s++)
		;
	sign = (*s == '-') ? -1 : 1;
	if (*s == '+' || *s == '-')
		s++;
	for (n =0; isdigit(*s); s++)
		n = 10 *n + *s - '0';
	return sign * n;
}

void reverse(char *);

/* itoa: conert n to characters in s; pointer version*/
void itoa(int n, char *s)
{
	int sign;
	char *t = s;

	if ((sign = n) < 0)
		n = -n;
	do {
		*s++ = n % 10 + '0';
	} while ((n /= 10) > 0);
	
	if (sign < 0)
		*s++ = '-';
	*s = '\0';
	reverse(t);
}


/*reverse: reverse string s in plcae*/
void reverse(char *s)
{
	int c;
	char *t;

	for (t = s + (strlen(s)-1); s < t; s++, t--) {
		c = *s;
		*s = *t;
		*t = c;
	}
}

int main(int argc, char *argv[])
{
	int i;
	char s[30];

	/*
	for ( i = 0; i < argc; i++)
		printf("%s%s", argv[i], (i < argc -1) ? " " : "");
	printf("\n");
	*/
	printf("%s\n", argv[1]);
	strcpy(s, argv[1]);
	reverse(s);
	printf("%s\n", s);
	
	return 0;
}

