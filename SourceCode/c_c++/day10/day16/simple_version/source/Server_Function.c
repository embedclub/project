
#include "../include/Server_Function.h"

//保存当前客户端传进来的消息
USER user = {0};

//保存客户端描述符
int clientfd[MAX_CLIENT] = {0};

//互斥量
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

//聊天信息
//char str[128] = {0};

int sockfd = 0;

//信号处理
void sigFunc(int signum)
{
	int i = 0;
	for(i = 0; i < MAX_CLIENT && clientfd[i] != 0; i++)
	{
		close(clientfd[i]);
	}
	close(sockfd);
	exit(-1);
}

void Server_Create()
{
	printf("创建服务器socket...\n");
	//1、创建socket
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(-1 == sockfd)
	{
		perror("socket failed");
		exit(-1);
	}
	//2、准备通信地址
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);
	inet_aton("172.16.7.50", &addr.sin_addr);
	printf("创建服务器通信地址172.16.7.50\n");
	
	//3、绑定socket和通信地址
	int res = bind(sockfd, (struct sockaddr *)&addr, sizeof(addr));
	if(-1 == res)
	{
		perror("bind failed");
		exit(-1);
	}
	printf("绑定服务器和通信地址...\n");

	//4、监听窗口
	res = listen(sockfd, MAX_CLIENT);
	if(-1 == res)
	{
		perror("listen failed");
		exit(-1);
	}
	printf("开始监听%d端口，等待客户端连接...\n", PORT);
}

pthread_t Deal_Client_Connect(int *clientfd)
{
	//5、处理接收客户端的连接请求（单个，主函数做循环）
	struct sockaddr_in fromaddr;	//用于保存客户端地址信息
	socklen_t len = sizeof(fromaddr);
	*clientfd = accept(sockfd, (struct sockaddr *)&fromaddr, &len);
	if(-1 == *clientfd)
	{
		perror("accept failed");
		exit(-1);
	}
	printf("客户端%s连接到服务器\n", inet_ntoa(fromaddr.sin_addr));
	
	//接收一个消息	
	recv(*clientfd, &user, sizeof(user), 0);
	Send_Inform();	

	//6、创建客户端对应的线程
	pthread_t id;
	//将客户端的描述符交给子线程
	pthread_create(&id, 0, Data_Interaction, (void *)*clientfd);

	

	//将id返回给主函数使用
	return id;
}

//子线程的主体函数
void *Data_Interaction(void *srg)
{
	//定义一个变量保存客户端的描述符
	int cfd = (int)srg;
	//接收数据
	while(1)
	{
		int res = recv(cfd, &user, sizeof(user), 0);
		int i = 0, j = 0;		
		if(0 == res)
		{
			for(i = 0; i < MAX_CLIENT; i++)
			{
				if(cfd == clientfd[i])
				{
					for(j = i; j < MAX_CLIENT-1 && clientfd[j+1] != 0; j++)
					{	
						clientfd[j] = clientfd[j+1];
					}
					break; 
				}	
			}
			pthread_exit(0);
		}		
		printf("%s说:%s\n", user.m_name, user.m_speck);
		char str_out[256] = {0};

		pthread_mutex_lock(&lock);

		sprintf(str_out, "%s说:%s", user.m_name, user.m_speck);
		for(i = 0; i < MAX_CLIENT && clientfd[i] != 0; i++)
		{
			if(cfd != clientfd[i])
			{
				printf("向%d客户端发送消息:%s\n", clientfd[i], str_out);
				send(clientfd[i], str_out, strlen(str_out), 0);
			}
		}
		pthread_mutex_unlock(&lock);
	}
}

//发送通知(例如欢迎消息)
void Send_Inform()
{
	char str_out[50] = {0};
	sprintf(str_out, "欢迎%s进入聊天室\n", user.m_name);
	int i = 0;
	for(i = 0; i < MAX_CLIENT && clientfd[i] != 0; i++)
	{
		printf("向%d客户端发送消息:%s", clientfd[i], str_out);
		send(clientfd[i], str_out, strlen(str_out), 0);
	}
}
