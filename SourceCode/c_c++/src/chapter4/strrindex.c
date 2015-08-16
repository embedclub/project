#include <stdio.h>
#define MAXLINE 1024 /* maximum input line length */
int getline(char line[], int max);
int strrindex(char s[], char t[]);
char pattern[] = "hello"; /* pattern to search for */

/* find all lines matching pattern */
int main()
{
	char line[MAXLINE];
	int found = 0;
	int num=0;
	while (getline(line, MAXLINE) > 0) 
	{
		num = strrindex(line, pattern);
		printf("the position is %d\n", num);
		if (num >= 0) 
		{
			printf("%s", line);
			found++;
		}
	}
	return found;
}

/* getline: get line into s, return length */
int getline(char s[], int lim)
{
	int c, i;
	i = 0;
	while (lim > 0 && (c=getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

/* Write the function strrindex(s,t), which returns the position
** of the rightmost occurrence of t in s, or -1 if there is none.
*/

int strrindex(char s[], char t[])
{
	int i, j, k;
	for (i = 0; s[i] != '\0'; i++) 
	{
		for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			return (i+k);
	}
	return -1;
}
