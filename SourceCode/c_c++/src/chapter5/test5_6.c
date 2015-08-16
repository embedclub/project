#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int i;
	char s[100];

	for ( i = 0; i < argc; i++)
		printf("%s%s", argv[i], (i < argc -1) ? " " : "");
	printf("\n");
	strcpy(s, argv[1]);
	strcat(s, argv[2]);
	
	return 0;
}
