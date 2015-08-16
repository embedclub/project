
#include "../include/Client_Function.h"

int sockfd = 0;

//保存自身信息
USER self = {0};

void sigFunc(int signum)
{
	exit(-1);
}

//输入当前的用户信息
void Input_User()
{
	printf("-------请输入当前用户的信息--------\n");
	printf("---昵称：");
	fgets(self.m_name, 20, stdin);
	printf("----------------------------------\n\n");
	Clear_Enter(self.m_name);
	
}

//清除回车
void Clear_Enter(char *str)
{
	int i = 0;
	while(str[i])
	{
		//printf("%d\n", str[i]);
		//sleep(1);
		if('\n' == str[i]) 
		{
			str[i] = '\0';
		}
		i++;
	}
}

void Client_Create()
{
	printf("创建客户端socket...\n");
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
	
	//3、连接到服务器
	int res = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
	if(res == -1)
	{
		perror("connect failed");
		exit(-1);
	}
	printf("连接服务器成功!\n\n");
	//调用用户信息输入函数	
	Input_User();
	
	//发送一个用户信息给服务器
	send(sockfd, &self, sizeof(self), 0);

}



//负责接收消息的进程
void *Data_Recv(void *srg)
{
	char speck[256] = {0};
	while(1)
	{
		memset(speck, 0, 256);
		int res = recv(sockfd, speck, sizeof(speck), 0);	
		if(0 == res) 
		{
			printf("\n\n-----服务器已经关闭，即将退出客户端-----\n\n");
			exit(-1);
		}
		sleep(1);
		if(strncmp(speck, "欢迎", 4))
		{
			print_other(speck);
		}
		else
		{
			print_system(speck);
		}
	}
}

//负责发送消息的线程
void *Data_Send(void *srg)
{
	char str[128] = {0};
	while(1)
	{
		print_self();
		fgets(self.m_speck, 256, stdin);
		send(sockfd, &self, sizeof(self), 0);
	}
}

void Pthread_Create()
{
	pthread_t id[2];
	pthread_create(id+0, NULL, Data_Recv, NULL);
	pthread_create(id+1, NULL, Data_Send, NULL);
}

//输出提示输入的部分
void print_self()
{
	printf("-----------请输入要说的话----------------\n");	
	printf("：");
	fflush(stdout);
}

//输出其他人的话
void print_other(char *str)
{
	printf("\n--------------别人说的话----------------\n");	
	printf("%s\n", str);
	print_self();
}

//输出系统消息：
void print_system(char *str)
{
	printf("\n----------------------------------------\n");
	printf("\n公告：%s", str);
	printf("\n----------------------------------------\n\n");
	print_self();
}
