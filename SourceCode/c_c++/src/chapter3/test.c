#include <stdio.h>

main()
{
	unsigned temp;
	temp = ((unsigned)~0) >> 10;
	printf("temp is %x\n",temp);

}
