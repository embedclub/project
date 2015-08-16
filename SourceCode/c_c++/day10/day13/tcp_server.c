#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define PORT 8888

int main()
{
	/*1 创建socket*/
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd == -1)
	{
		perror("socket failed");
		exit(-1);
	}
	/*2 准备通信地址*/
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port	= htons(PORT);
	inet_aton("192.168.182.10", &addr.sin_addr);
	
	/*3 绑定socket和通信地址*/
	int res = bind(sockfd,(struct sockaddr *)&addr,
           			sizeof(addr));
	if(res == -1)
	{
		perror("bind failed");
		exit(-1);
	}
	/*4 监听端口*/
	res = listen(sockfd, 100);
	if(res == -1)
	{
		perror("listen failed");
		exit(-1);
	}
	printf("开始监听%d端口，等待客户端连接...\n",
			PORT);
	/*5 处理接收客户端的连接请求*/
	//用于保存客户端地址信息
	struct sockaddr_in fromaddr;
	/*len 取0会是什么效果？*/
	socklen_t len = sizeof(fromaddr);
	int clientfd = accept(sockfd, 
					(struct sockaddr *)&fromaddr,
					&len);
	if(clientfd == -1)
	{
		perror("accept failed");
		exit(-1);
	}
	printf("有一个客户端连接到服务器，它是:%s\n",
			inet_ntoa(fromaddr.sin_addr));
	/*6 处理客户端数据*/
	char buf[100] = {0};
	int count = recv(clientfd, buf, sizeof(buf),0);
	printf("从客户端读取到%d字节：%s\n",
			count, buf);
	char *str = "欢迎你客户端";
	send(clientfd, str, strlen(str), 0);
	/*关闭连接*/
	close(clientfd);
	close(sockfd);
	return 0;
}
