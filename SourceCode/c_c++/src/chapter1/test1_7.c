/*
7、编写一个程序，删除每个输入行末尾的空格。
*/

/*remove the blanks of the end of lines*/
#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
int remove_blank(char s[]);

int main()
{
	char line[MAXLINE];
	while (getline(line, MAXLINE) > 0 )
		if (remove_blank(line) > 0)
			printf("Modified the line is:%s\n", line);
	return 0;
}

int remove_blank(char s[])
{
	int i = 0;
	while (s[i] != '\n')
		++i;
	--i;
	while ((i >=0) && (s[i] == ' '))
		--i;
	if (i >= 0) {
		++i;
		s[i] = '\n';
		++i;
		s[i] = '\0';
	}
	printf("the modified string length is: %d\n", i);
	return i;
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




