/*htoi: convert hexadecimal string to integer*/

#include <stdio.h>
#include <string.h>


void squeeze(char s1[], char s2[])
{
	int i, j, k;

	for (i=k=0; s1[i] != '\0'; i++) {
		for (j=0; s2[j] != '\0' && s2[j] != s1[i]; j++);
		if (s2[j] == '\0')
			s1[k++] = s1[i];
	}
	s1[k] = '\0';
	
}
main()
{
	char s1[50];
	gets(s1);
	char s2[50];
	gets(s2);
	printf(" s1 is : %s\n", s1);
	printf(" s2 is : %s\n", s2);
	squeeze(s1, s2);
	printf("the modified s1 is: %s\n", s1);
}

