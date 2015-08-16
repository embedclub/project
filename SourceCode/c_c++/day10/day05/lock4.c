#include "public.h"

void print_locktype(struct flock lock)
{
	switch(lock.l_type)
	{
		case F_RDLCK:
			printf("F_RDLCK\n");
			break;
		case F_WRLCK:
			printf("F_WRLCK\n");
			break;
		case F_UNLCK:
			printf("F_UNLCK\n");
			break;
	}
}

int main()
{
	int fd = open("a.txt", O_RDWR);
	/*准备一把读锁*/
    struct flock rlock;
	rlock.l_type = F_RDLCK;
	rlock.l_whence = SEEK_SET;
	rlock.l_start = 0;
	rlock.l_len = 20;
	rlock.l_pid = -1;
	/*测试rlock这把锁是否可以加到a.txt上去
     *如果执行完F_GETLK后，lock中的数据除了
     *锁类型变为F_UNLCK外，其他数据没有变化
     *说明这把锁可以加上去
     */
	int res = fcntl(fd, F_GETLK, &rlock);
	print_locktype(rlock);
	if(res == -1)
	{
		perror("getlock failed!");
		return -1;
	}
	if(rlock.l_pid == -1)
	{
		printf("a.txt 从0~20可以加读锁\n");
	}
	else
	{
		printf("a.txt 从0~20位置不能加读锁");
	}
	/*准备写锁*/	
	struct flock wlock;
	wlock.l_type = F_WRLCK;
	wlock.l_whence = SEEK_SET;
	wlock.l_start = 20;
	wlock.l_len = 30;
	wlock.l_pid = -1;

	/*测试写锁是否可以加到a.txt上去
     *如果加不上，系统会将加不此锁的原因（有另外一把锁的存在）找出来，并把存在的那把锁保存到wlock 
	*/
	fcntl(fd, F_GETLK, &wlock);	
	print_locktype(wlock);
	if(wlock.l_pid == -1)
	{
		printf("文件20~50的位置可以加锁\n");
	}
	else
	{
		printf("文件20~50的位置不可以加锁\n");
	printf("是因为进程%d在文件中从%d到%d加了锁\n",
			wlock.l_pid, (int)wlock.l_start, 
			(int)(wlock.l_start + wlock.l_len));
	}





}
