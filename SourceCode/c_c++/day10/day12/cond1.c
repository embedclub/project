
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

int main()
{
	key_t key1 = ftok("./", 100);
	key_t key2 = ftok("./", 102);
	int shm_id = shmget(key1, 26, 
						IPC_CREAT|0666);
	int sem_id = semget(key2, 1,
						IPC_CREAT|0666);
	void *p = shmat(shm_id, 0, 0);
	/*信号量初值为0*/
	semctl(sem_id, 0, SETVAL, 0);
	struct sembuf op = {0};
	op.sem_num = 0;
	op.sem_op  = 1;
	op.sem_flg = 0;
	int i = 0;
	char *str = p;
	for(; i<26; i++)
	{
		*(str + i) = 'A' + i;
		//信号量+1
		semop(sem_id, &op, 1);
		sleep(1);
	}

	shmdt(p);

	/*销毁共享内存 信号量集*/


}

