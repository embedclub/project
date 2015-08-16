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
	/*设置为服务器进程的端口号*/
	addr.sin_port	= htons(PORT);
	/*服务器所在主机IP地址*/
	inet_aton("192.168.182.10", &addr.sin_addr);
	
	/*3 连接服务器*/
	int res = connect(sockfd, 
					  (struct sockaddr *)&addr,
					  sizeof(addr));
	if(res == -1)
	{
		perror("connect failed");
		exit(-1);
	}
	printf("连接服务器成功....\n");
	/*4 和服务器交换数据*/
	char buf[100] = {0};
	char *str = "借点钱可以吗...";
	write(sockfd, str, strlen(str))	;
	read(sockfd, buf, sizeof(buf));
	printf("服务器说:%s\n", buf);

	/*关闭连接*/
	close(sockfd);
	return 0;
}
