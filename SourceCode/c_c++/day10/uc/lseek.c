
#include "public.h"

int main()
{
	int fd = open("a.txt", O_RDWR);
	
	char ch;
	read(fd, &ch, 1);//offset++
	printf("%c\n",ch);
	lseek(fd, 5, SEEK_CUR);//offset+5
	
	read(fd, &ch, 1);//offset++
	printf("%c\n",ch);

	lseek(fd, 1024, SEEK_CUR);
	write(fd, "abc", 3);
	return 0;
}


