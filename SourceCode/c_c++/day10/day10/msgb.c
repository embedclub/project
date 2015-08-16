
#include "public.h"
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
int main()
{
	key_t key = QUEUE_KEY;
	/*获取消息队列*/
	int msgid = msgget(key, 0);
	if(msgid == -1)
	{
		perror("msgget failed!");
		exit(-1);
	}
	/* 从消息队列中读出数据*/
	char buf[100] = {0};
	int res = msgrcv(msgid, buf, 100, 0, 0);
	if(res == -1)
	{
		perror("msgrcv failed!\n");
		exit(-1);
	}	

	printf("接收到%d字节的数据: %s\n", res, buf);
	return 0;
}

