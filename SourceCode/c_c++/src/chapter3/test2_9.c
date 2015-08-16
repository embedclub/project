/*escape: expand newline and tab into visible sequences while copying the string t to s*/

#include <stdio.h>
#include <string.h>
//#include <stdlib.h>

void escape(char s[], char t[])
{
	int i, j;

	for (i =j =0; t[i] != '\0'; i++)
		switch (t[i]) {
			case '\n':
				s[j++] = '\\';
				s[j++] = 'n';
				break;
			case '\t':
				s[j++] = '\\';
				s[j++] = 't';
				break;
			default:
				s[j++] = t[i];
				break;
		}
	s[j] = '\0';
}


/* unescape: convert escape sequences into real characters while copying the string t ro s */
void unescape(char s[], char t[])
{
	int i, j;

	for (i =j=0; t[i] != '\0'; i++)
		if (t[i] != '\\')
			s[j++] = t[i];
		else
			switch(t[++i]) {
				case 'n':
					s[j++] = '\n';
					break;
				case 't':
					s[j++] = '\t';
					break;
				default:
					s[j++] = '\\';
					s[j++] = t[i];
					break;
				}
	s[j] = '\0';
}

main()
{
	char t[30];
	char s[30];
	int i=0;
	char c;
	while ((c = getchar()) != EOF)
		t[i++] = c;
	t[i] = '\0';
		
	escape(s, t);	
	printf("After escape  the string s[] is: %s\n", s);

	unescape(s, t);	
	printf("After unescape  the string s[] is: %s\n", s);
}

