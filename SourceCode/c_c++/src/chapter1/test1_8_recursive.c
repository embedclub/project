/*
8¡¢±àĞ´º¯Êıreverse()£¬½«×Ö·û´®sÖĞµÄ×Ö·ûË³Ğòµßµ¹¹ıÀ´¡£
µİ¹é°æ
*/

#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getline(char s[], int len);
void reverser(char s[], int i, int len);

main()
{
	char s[MAXLINE];
	
	while(getline(s, MAXLINE) > 0) {
		reverser(s, 0, strlen(s));
		printf("%s", s);
	}
}

void reverser(char s[], int i, int len)
{
	int c, j;
	j = len - (i + 1);
	if (i < j) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		reverser(s, ++i, len);
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
