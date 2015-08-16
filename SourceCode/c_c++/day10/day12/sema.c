#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main()
{
	/*生成key*/
	key_t key = ftok("./", 100);
	/*2 创建信号量集*/
	int semid = semget(key, 1, IPC_CREAT|0666);
	/*3 初始化信号量集，给集合中的每个信号量赋初值*/
	if(semctl(semid, 0, SETVAL, 5) == -1)
	{
		perror("semctl failed");
		exit(-1);
	}
	printf("按下回车销毁信号量集合...\n");
	getchar();
	
	/*销毁*/
	semctl(semid, 0,IPC_RMID);
	return 0;
}
