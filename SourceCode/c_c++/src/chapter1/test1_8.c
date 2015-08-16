/*
8、编写函数reverse()，将字符串s中的字符顺序颠倒过来。
*/

#include <stdio.h>
#define MAXLINE 1000

int getline(char s[], int len);
void reverse(char s[]);

main()
{
	char line[MAXLINE];
	
	while(getline(line, MAXLINE) > 0) {
		reverse(line);
		printf("%s\n", line);
	}
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

int getline(char s[], int len)
{
	int c, i;
	for (i = 0; i <len-1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

