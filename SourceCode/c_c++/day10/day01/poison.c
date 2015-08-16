
#include "global.h"

int main()
{
	goto failed;
	printf("hello!\n");
	return 0;

failed:
	printf("failed!\n");
	return -1;

}

