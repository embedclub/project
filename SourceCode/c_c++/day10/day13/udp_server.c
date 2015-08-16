#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 12345
int main()
{
	/*1 创建socket*/	
	int sd = socket(PF_INET, SOCK_DGRAM, 0);
	if(sd == -1)
	{
		perror("socket failed");
		exit(-1);
	}
	/*2 准备地址*/
	struct sockaddr_in addr;
	addr.sin_family = PF_INET;
	addr.sin_port = htons(PORT);
	inet_aton("192.168.182.10",  &addr.sin_addr);
	/*3 socket addr 绑定*/
	int res = bind(sd, (struct sockaddr *)&addr,
					sizeof(addr));
	if(res == -1)
	{
		perror("bind failed");
		exit(-1);
	}
	/*4 进行通信*/
	while(1)
	{
		char buf[100] = {0};
		struct sockaddr_in fromaddr;
		int len = sizeof(fromaddr);
		recvfrom(sd, buf, sizeof(buf), 0,
				 (struct sockaddr *) &fromaddr,
				 &len);
		printf("从客户端%s接收到数据:%s\n",
				inet_ntoa(fromaddr.sin_addr),
				buf);
		char *str = "没问题，借多少";
		sendto(sd, str, strlen(str), 0,
				(struct sockaddr *)&fromaddr,
				sizeof(fromaddr));
	}
	close(sd);

}








