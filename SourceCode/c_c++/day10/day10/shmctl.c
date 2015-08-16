
#include "public.h"
#include <sys/types.h>
#include <sys/shm.h>
#include <time.h>

int main()
{
	key_t key = ftok(".", 200);
	int shmid = shmget(key, 0, 0);
	/*获取共享内存的属性*/
	struct shmid_ds ds;
	shmctl(shmid, IPC_STAT, &ds);
	
	printf("key = %#x\n", ds.shm_perm.__key);
	printf("mod = %#o\n", ds.shm_perm.mode);
	printf("size = %d\n", ds.shm_segsz);
	printf("nattch=%d\n", (int)ds.shm_nattch);
	printf("atime=%s\n", ctime(&ds.shm_atime));
	
	return 0;
}




