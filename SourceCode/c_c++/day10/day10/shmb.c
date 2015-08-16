
#include "public.h"
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
	/*1. 生成key*/
	//key_t key = ftok("/home/tarena/1407/uc/day10", 200);
	key_t key = ftok(".", 200);
	/*2 获取共享内存区域*/
	int shmid = shmget(key, 0,0); 
	if(shmid == -1)
	{
		perror("shmget failed");
		exit(-1);
	}
	printf("获取共享内存成功！\n");
	/*3 映射共享内存, 读写方式访问*/
	void *p = shmat(shmid, 0, 0);
	if(p == (void *)-1)
	{
		perror("shmat failed!");
		exit(-1);
	}
	printf("映射成功，首地址=%p\n", p);
	/*4 以读写方式进行通信*/
	printf("共享内存前4字节为：%d\n", *((int *)p));	   printf("共享内存接下来的字符串为:%s\n",
			(char *)(p+4));
	
	/*5 解除映射*/
	if(shmdt(p) == -1)
	{
		perror("shmdt failed!");
		exit(-1);
	}
	printf("解除映射成功！\n");
	
}

