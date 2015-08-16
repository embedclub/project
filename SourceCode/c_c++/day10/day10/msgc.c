
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
	/* 向消息队列中写入有类型消息*/
	struct MSG msg1;	
	struct MSG msg2;	
	msg1.mtype = 2;
	strcpy(msg1.buf, "nihao!");
	/*size ,指的是msg1.buf大小
			忽略mtype所占内存空间
    */
	int res = msgsnd(msgid, &msg1, 
					 sizeof(msg1.buf), 0);
	if(res == -1)
	{
		perror("msgsnd failed!\n");
		exit(-1);
	}	
	msg2.mtype = 1;
	strcpy(msg2.buf, "hello!");
	/*size ,指的是msg2.buf大小
			忽略mtype所占内存空间
    */
	res = msgsnd(msgid, &msg2, 
					 sizeof(msg2.buf), 0);
	if(res == -1)
	{
		perror("msgsnd failed!\n");
		exit(-1);
	}	
	printf("按下回车销毁消息队列...\n");
	getchar();
	/*销毁消息队列*/
	msgctl(msgid, IPC_RMID, NULL);

}

