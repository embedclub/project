
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
	printf("cat /proc/%d/maps", getpid());
	getchar();
	
	int *p1 = malloc(sizeof(int));
	p1[0] = 0x55;
	p1[1] = 0x55;
	p1[2] = 0x55;
	p1[3] = 0x0;
	int *p2 = malloc(sizeof(int));
	printf("%p, %p, \n", p1,p2);
	//*(p1 + 33*1024) = 0x55;
	getchar();
	printf("free after cat /proc/xxx/maps\n");
	free(p1);
	free(p2);
	while(1);
	return 0;
}


