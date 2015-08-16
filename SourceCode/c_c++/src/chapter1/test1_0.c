#include <stdio.h>

main()
{
	char c;
	while ((c = getchar()) != EOF)
		putchar(c);
	printf("\n the EOF is:%d\n",EOF);
}
