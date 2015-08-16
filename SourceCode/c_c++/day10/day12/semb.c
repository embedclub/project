#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

void operation(int semid)
{
	/*4 访问共享资源前信号量-1*/
	struct sembuf op = {0};
	op.sem_num = 0;//第0个信号量
	op.sem_op = -1;//-1操作
	op.sem_flg = 0;// 不成功则阻塞
	semop(semid, &op, 1);
	printf("进程%d 访问共享资源...\n",getpid());
	sleep(20);
	printf("进程%d 完成共享资源的访问\n", getpid());	
	/*访问共享资源结束后信号量+1*/
	op.sem_op = 1;// +1 操作
	semop(semid, &op, 1);
}

int main()
{
	/*生成key*/
	key_t key = ftok("./", 100);
	/*2 获取信号量集*/
	int semid = semget(key, 0, 0);
	/*3 使用信号量集合*/
    int i  = 0;
	for(; i<10; i++)
	{
		int pid = fork();
		if(pid == 0)
		{
			operation(semid);
			exit(0);
		}
	}	
	return 0;
}
