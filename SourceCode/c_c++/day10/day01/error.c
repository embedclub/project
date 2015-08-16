#include <stdio.h>

#if (VERSION < 3)
	#error "版本太低"
#elif(VERSION >3)
	#warning "版本过高"
#endif

int main(void)
{
	printf("版本号： %d\n", VERSION);
	return 0;
}


