
#include "public.h"

int main()
{
	int fd = open("a.txt", O_RDWR);
	/*a.txt文件的10~30上读锁*/
	/*1准备一把锁*/
    struct flock rlock;
	rlock.l_type = F_RDLCK;
	rlock.l_whence = SEEK_SET;
	rlock.l_start = 10;
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
	sleep(30);
	printf("read ok\n");
	/*释放锁*/
    rlock.l_type = F_UNLCK;
	fcntl(fd, F_SETLK, &rlock);
	
	printf("rlock released!\n");
    sleep(30);
	close(fd);
	return 0;
}
