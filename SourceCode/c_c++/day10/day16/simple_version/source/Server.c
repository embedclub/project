
#include "../include/Server.h"

int main()
{
	//信号处理
	signal(SIGINT, sigFunc);
	extern int clientfd[MAX_CLIENT];

	pthread_t id[MAX_CLIENT];
	int i = 0;

	Server_Create();

	while(1)
	{
		//找一个0的位置插进去
		for(i = 0; i < MAX_CLIENT && clientfd[i] != 0; i++);
		
		id[i] = Deal_Client_Connect(clientfd+i);		
	}

}
