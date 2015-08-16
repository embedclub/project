
#include "public.h"

int main()
{
	int fd = open("a.txt", O_RDWR);
	/*准备锁*/
    struct flock wlock;
	wlock.l_type = F_WRLCK;
	wlock.l_whence = SEEK_SET;
	wlock.l_start  = 20;
	wlock.l_len   = 10;
	wlock.l_pid = -1;
	/*加锁*/
    int res = fcntl(fd, F_SETLKW, &wlock);
	if(res == -1)
	{
		perror("write lock failed!\n");
		return -1;
	}
	printf("write lock successed!\n");
	return 0;
}
