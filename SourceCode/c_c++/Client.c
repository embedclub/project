/************************Copyright(c)*******************************
**------------------------------------------FileInfo-------------------------------------------------------
** File name:               Client.c
** Last modified Date:  	2015-1-7
** Last Version:            	1.0
** Descriptions:            
**------------------------------------------------------------------------------------------------------
** Created by:            	Alex
** Created date:       		2015-1-7
** Version:                 	1.0
** E-mail:			shidaoxuan@hotmail.com            	
**------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
** Version:
** Descriptions:
*******************************************************************/
#include<stdio.h>      		/*标准输入输出定义*/
#include<stdlib.h>     		/*标准函数库定义*/
#include<unistd.h>     		/*Unix标准函数定义*/
#include<sys/types.h> 
#include<sys/stat.h>   
#include<fcntl.h>      		/*文件控制定义*/
#include<termios.h>    		/*PSIX 终端控制定义*/
#include<errno.h>     		/*错误号定义*/
#include<string.h>
#include <errno.h> 
#include <netdb.h> 
#include <netinet/in.h> 
#include <sys/socket.h> 
 
#define	FALSE  	-1
#define TRUE  	 0
#define MAX_REC_BUFF  200
#define MY_PORT 	3000

 /*主函数体*/
int main(int argc, char **argv)
{
	int sockfd,recbytes;                            		//socket描述符
	char rcv_buf[MAX_REC_BUFF];       
	struct hostent *host;
	struct sockaddr_in serv_addr;
	
	if(argc != 3){
		printf("Usage: %s  Hostname r\n",argv[0]);
		return FALSE;
	}
	
	if ((host= gethostbyname(argv[1])) == NULL)
	{
		perror("gethostbyname");
		return FALSE;
	}
	
	memset(rcv_buf,0,sizeof(rcv_buf));
	if((sockfd = socket(AF_INET, SOCK_STREAM, 0))== -1)
	{
		perror("socket");
		return FALSE;
	}
	
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(MY_PORT);
	serv_addr.sin_addr= *((struct in_addr *)host->h_addr);
	bzero(&(serv_addr.sin_zero), 8 );
	
	if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(struct sockaddr))== -1)
	{
		perror("connect");
		return FALSE;
	}
	/* 连接成功了 */ 
	printf("CONNECT SUCCESS!\n");
	
	while (1)
	{
		if ((recbytes= recv(sockfd,rcv_buf,MAX_REC_BUFF,0))== -1)
		{
			perror("recv");
			return FALSE;
		}
		printf("%s",rcv_buf);
	}
	/* 结束通讯 */ 
	close(sockfd); 
	return 0;
}
  
/***********End Of File************/
