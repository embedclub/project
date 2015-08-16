
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
	struct MSG msg;
	msgrcv(msgid, &msg, sizeof(msg.buf), 1, 0);	
	printf("接收到的消息类型=%ld, 消息内容：%s\n",
			msg.mtype, msg.buf);
	return 0;
}

