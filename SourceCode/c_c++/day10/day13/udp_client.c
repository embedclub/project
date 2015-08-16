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
	/*3 进行通信*/
	char *str = "借点钱可以吗";
	sendto(sd, str, strlen(str), 0,
			(struct sockaddr *)&addr,
			sizeof(addr));
	char buf[100] = {0};
	int len = sizeof(addr);
	recvfrom(sd, buf, sizeof(buf), 0,
			(struct sockaddr *) &addr,
			  &len);
	printf("服务器说：%s\n", buf);
	close(sd);
}








