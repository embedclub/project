
#include "public.h"
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
int main()
{
	key_t key = QUEUE_KEY;
	/*创建消息队列*/
	int msgid = msgget(key, 
					   IPC_CREAT|IPC_EXCL|0666);
	if(msgid == -1)
	{
		perror("msgget failed!");
		exit(-1);
	}
	/* 向消息队列中写入数据*/
	char *str = "hello message!";
	int res = msgsnd(msgid, str, strlen(str), 0);
	if(res == -1)
	{
		perror("msgsnd failed!\n");
		exit(-1);
	}	
	printf("msgsnd successed!\n");
	printf("按下回车销毁消息队列...\n");
	getchar();
	/*销毁消息队列*/
	msgctl(msgid, IPC_RMID, NULL);

}

