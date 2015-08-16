
#include "public.h"

int main()
{
	int fd = open("a.txt", O_RDWR|O_CREAT, 0644);
	
	int i = 0;
	char c = '0';
	for(; i<10000000; i++)
	{
		usleep(1000);
		write(fd, &c, 1);
		c++;
		if(c > '9')
		{
			c = '0';
		}
	}	
	return 0;
}

