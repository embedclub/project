
#include "public.h"

int main()
{
	int fd = open("a.txt", O_RDWR);
	/*a.txt文件的0~20上读锁*/
	/*1准备一把锁*/
    struct flock rlock;
	rlock.l_type = F_RDLCK;
	rlock.l_whence = SEEK_SET;
	rlock.l_start = 0;
	rlock.l_len = 20;	
	rlock.l_pid = -1;
	/*2 给文件加锁*/
    int res = fcntl(fd, F_SETLK, &rlock);
	if(res == -1)
	{
		perror("rlock failed!");
		return -1;
	}
	printf("rlock successed!\n");
	lseek(fd, 10, SEEK_SET);
	printf("reading file ...\n");
	sleep(10);
	printf("read ok\n");

	/*准备锁*/
    struct flock wlock;
	wlock.l_type = F_WRLCK;
	wlock.l_whence = SEEK_SET;
	wlock.l_start  = 0;
	wlock.l_len   = 50;
	wlock.l_pid = -1;
	/*加锁*/
    res = fcntl(fd, F_SETLK, &wlock);
	if(res == -1)
	{
		perror("write lock failed!\n");
		return -1;
	}
	printf("write lock successed!\n");
	return 0;
}
