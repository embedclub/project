
#include "public.h"

int main()
{
	int fd = open("a.txt", O_RDWR|O_CREAT, 0644);
	
	int i = 0;
	char c = 'a';
	for(; i<10000000; i++)
	{
		usleep(1000);
		write(fd, &c, 1);
		c++;
		if(c > 'z')
		{
			c = 'a';
		}
	}	
	return 0;
}

