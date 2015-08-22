/************************Copyright(c)*******************************
**------------------------------------------FileInfo-------------------------------------------------------
** File name:               	serialCom.c
** Last modified Date:  	2014-12-11
** Last Version:            	1.0
** Descriptions:            
**------------------------------------------------------------------------------------------------------
** Created by:            	Alex
** Created date:       		2014-12-11
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
#define MAX_CONN_NUM 	5
/*******************************************************************
* 名称：           		UART_OPEN
* 功能：           	打开串口并返回串口设备文件描述
* 入口参数：       	fd	:文件描述符     
			port 	:串口号(ttySAC1,ttySAC2)
* 出口参数：       	正确返回为1，错误返回为0
*******************************************************************/
int UART_OPEN(int fd,char* port)
{
	fd = open( port, O_RDWR|O_NOCTTY|O_NONBLOCK);

	if (FALSE == fd){
		perror("Can't Open Serial Port");
		return(FALSE);
	}                          

	if(fcntl(fd, F_SETFL, 0) < 0){				//恢复串口为阻塞状态  
		printf("fcntl failed!\n");
		return(FALSE);
	}     


	if(0 == isatty(fd)){						//测试是否为终端设备 Parm:STDIN_FILENO
		printf("This is not a terminal device\n");
		return(FALSE);
	}	              
	printf("!!OPEN ttyS* SUCCESS!....\n");
	return fd;
}

/*******************************************************************
* 名称：            UART_CLOSE
* 功能：            关闭串口并返回串口设备文件描述
* 入口参数：        fd:文件描述符     port :串口号(ttySAC1,ttySAC2)
* 出口参数：        void
*******************************************************************/
void UART_CLOSE(int fd)
{
    close(fd);
}
 
/*******************************************************************
* 名称：            	UART_CONFIG
* 功能：            设置串口数据位，停止位和效验位
* 入口参数：        fd 			:串口文件描述符
*                   speed     	:串口速度
*                   flow_ctrl  	:数据流控制
*                   databits   	:数据位   取值为 7 或者8
*                   stopbits   	:停止位   取值为 1 或者2
*                   parity     	:效验类型 取值为N,E,O,,S
*出口参数：         正确返回为1，错误返回为0
*******************************************************************/
int UART_CONFIG(int fd,int speed,int flow_ctrl,int databits,int stopbits,int parity)
{
   
	int   i;
	int   status;
	speed_t  speed_arr; 
    struct   termios new_options,old_options;
   
	/****tcgetattr(fd,&options)得到与fd指向对象的相关参数，并将它们保存于options,
	该函数还可以测试配置是否正确，该串口是否可用等。若调用成功，函数返回值为0，
	若调用失败，函数返回值为1.	****/
	if  ( tcgetattr( fd,&old_options)  !=  0){
		perror("tcgetattr\n");    
		return(FALSE); 
	}
	memset(&new_options,0,sizeof(new_options));
	new_options=old_options;
	new_options.c_cflag |= CLOCAL |CREAD;		//激活本地和接收
	new_options.c_cflag &= ~CSIZE;				//屏蔽其他标志位
	//选择串口模式:规范模式+非规范模式+原始模式
	
	//设置串口输入波特率和输出波特率
	switch(speed)
	{
	case 4800	:
		speed_arr=B4800;
		break;
	case 9600	:
		speed_arr=B9600;
		break;
	case 115200	:
		speed_arr=B115200;
		break;
	default		:
		speed_arr=B115200;
		break;
	}
	cfsetispeed(&new_options, speed_arr); 
	cfsetospeed(&new_options, speed_arr);  
  
	switch(flow_ctrl)			//设置数据流控制
	{
	case 0 :			//不使用流控制
		new_options.c_cflag &= ~CRTSCTS;
		break;   
	case 1 :			//使用硬件流控制
		new_options.c_cflag |= CRTSCTS;
		break;
	case 2 :			//使用软件流控制
		new_options.c_cflag |= IXON | IXOFF | IXANY;
		break;
	}

	switch (databits)		//设置数据位
	{  
	case 5    :
		new_options.c_cflag |= CS5;
		break;
	case 6    :
		new_options.c_cflag |= CS6;
		break;
	case 7    :    
		new_options.c_cflag |= CS7;
		break;
	case 8:    
		new_options.c_cflag |= CS8;
		break;  
	default:   
		perror("databits\n");
		return (FALSE); 
	}
  
	switch (parity)		  //设置校验位
	{  
	case 'n':
	case 'N': 		//无奇偶校验位。
		new_options.c_cflag &= ~PARENB; 
		new_options.c_iflag &= ~INPCK;    
		break; 
	case 'o':  
	case 'O':		//设置为奇校验    
		new_options.c_cflag |= (PARODD | PARENB); 
		new_options.c_iflag |= INPCK;             
		break; 
	case 'e': 
	case 'E':		//设置为偶校验  
		new_options.c_cflag |= PARENB;       
		new_options.c_cflag &= ~PARODD;       
		new_options.c_iflag |= INPCK;      
	    break;
	case 's':
	case 'S': 		//设置为空格 
		new_options.c_cflag &= ~PARENB;
		new_options.c_cflag &= ~CSTOPB;
		break; 
	default:  
		perror("parity\n");    
		return (FALSE); 
	} 

	switch (stopbits)			// 设置停止位 
	{  
	case 1:   
		new_options.c_cflag &= ~CSTOPB; break; 
	case 2:   
		new_options.c_cflag |= CSTOPB; break;
	default:   
		perror("stopbits\n"); 
		return (FALSE);
	}
//	options.c_iflag |= ICRNL;
// 	options.c_oflag |= ONLCR;
//	options.c_oflag &= ~OPOST;		  //修改输出模式，原始数据输出
//	options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);//我加的
//	options.c_lflag &= ~(ISIG | ICANON);
	new_options.c_lflag |= (ICANON | ECHO | ECHOE | IEXTEN);
   
	//设置等待时间和最小接收字符
// 	options.c_cc[VTIME] = 1; /* 读取一个字符等待1*(1/10)s */  
// 	options.c_cc[VMIN] = 1; /* 读取字符的最少个数为1 */
	
	//如果发生数据溢出，接收数据，但是不再读取 刷新收到的数据但是不读
	tcflush(fd,TCIFLUSH);
	
	//激活配置 (将修改后的termios数据设置到串口中）
	if (tcsetattr(fd,TCSANOW,&new_options) != 0)  {
		perror("tcsetattr\n");  
		return (FALSE); 
	}
	return (TRUE); 
}

/*******************************************************************
* 名称：                UART_DEFAULT()
* 功能：                串口初始化
* 入口参数：    fd       	:文件描述符   
*               speed  	 	:串口速度
*               flow_ctrl 	:数据流控制
*               databits  	:数据位   取值为 7 或者8
*               stopbits  	:停止位   取值为 1 或者2
*               parity    	:效验类型 取值为N,E,O,,S
*                      
* 出口参数：        正确返回为1，错误返回为0
*******************************************************************/
int UART_DEFAULT(int fd)
{
	if (UART_CONFIG(fd,115200,0,8,1,'N') == FALSE)		//设置串口数据帧格式                                                      
		return FALSE;
	else
		return  TRUE;
}
 
/*******************************************************************
* 名称：                  UART_RECV
* 功能：                接收串口数据
* 入口参数：        fd 			:文件描述符    
*                   rcv_buf     	:接收串口中数据存入rcv_buf缓冲区中
*                   data_len    	:一帧数据的长度
* 出口参数：        正确返回为1，错误返回为0
*******************************************************************/
int UART_RECV(int fd, char *rcv_buf,int data_len)
{
	int len,fs_sel;
	fd_set fs_read;
	struct timeval time;

	FD_ZERO(&fs_read);
	FD_SET(fd,&fs_read);

	time.tv_sec = 10;
	time.tv_usec = 0;
	
	fs_sel = select(fd+1,&fs_read,NULL,NULL,&time);			//使用select实现串口的多路通信
	if(fs_sel && FD_ISSET(fd,&fs_read))
	{
		len = read(fd,rcv_buf,data_len);
		return len;
	}
	else
		return FALSE;    
}

/********************************************************************
* 名称：                  UART_SEND
* 功能：                  发送数据
* 入口参数：        fd  		:文件描述符    
*                   send_buf    	:存放串口发送数据
*                   data_len    	:一帧数据的个数
* 出口参数：        正确返回为len，错误返回为0
*******************************************************************/
int UART_SEND(int fd, char *send_buf,int data_len)
{
	int len = 0;
	len = write(fd,send_buf,data_len);
	if (len == data_len )
		return len;
	else   
	{
		tcflush(fd,TCOFLUSH);
		return FALSE;
	}
}
 
 /*主函数体*/
int main(int argc, char **argv)
{
	int fd;                            		//文件描述符
	int err;                          	 	//返回调用函数的状态
	int len;                        
	int i;
	char rcv_buf[200];       
	char send_buf[30]="**This's a GPS Locator!**\n";
	int listen_fd,accept_fd;
	struct sockaddr_in     client_addr;
	int n;
//	int nbytes;
	
	if(argc != 3){
		printf("Usage: %s  /dev/ttyS*  s-Send/r-Receive\n",argv[0]);
		return FALSE;
	}
	fd = UART_OPEN(fd,argv[1]);		 //打开串口，返回文件描述符
	
	do{
		err = UART_DEFAULT(fd);
	}while(FALSE == err || FALSE == fd);
	printf("Port is READY!\n");
	
	if((listen_fd=socket(AF_INET,SOCK_STREAM,0))<0)		//创建socket
  	{
        printf("Socket Error:%s\n\a",strerror(errno));
		return FALSE;
  	}
	bzero(&client_addr,sizeof(struct sockaddr_in));
 	client_addr.sin_family=AF_INET;
 	client_addr.sin_port=htons(MY_PORT);
 	client_addr.sin_addr.s_addr=htonl(INADDR_ANY);
 	n=1;
 	setsockopt(listen_fd,SOL_SOCKET,SO_REUSEADDR,&n,sizeof(int)); //如果服务器终止后,服务器可以第二次快速启动而不用等待一段时间
	if(bind(listen_fd,(struct sockaddr *)&client_addr,sizeof(client_addr))<0)	//Bind 
  	{
        printf("Bind Error:%s\n\a",strerror(errno));
		return FALSE;
  	}
	listen(listen_fd,MAX_CONN_NUM);
	
	if(0 == strcmp(argv[2],"s"))
	{
		for(i = 0;i < 50;i++)
		{
			len = UART_SEND(fd,send_buf,30);
			if(len > 0)
				printf("Count.%d :Send data successful!\n",i);
			else
				printf("Count.%d :Send data failed!\n",i);
			sleep(1);
		}        
	}
    else if(0 == strcmp(argv[2],"r"))
	{
		while (1) 					//循环读取数据
		{  
			accept_fd=accept(listen_fd,NULL,NULL);
			if((accept_fd<0)&&(errno==EINTR))
				continue;
			else if(accept_fd<0)
			{
				printf("Accept Error:%s\n\a",strerror(errno));
				continue;
			}			
			if((n=fork())==0)
			{
				/* 子进程处理客户端的连接 */
				unsigned int i;
				for(i=0;i<200;i++){
					len = UART_RECV(fd, rcv_buf,MAX_REC_BUFF);
				if(len > 0)
					write(accept_fd,rcv_buf,len);
				else
					printf("(Time limit)No data now!\n");
				}
				close(accept_fd);
				exit(0);
			}
			else if(n<0)
				printf("Fork Error:%s\n\a",strerror(errno));
		}       
	}
	else 
	{
	   fprintf(stderr,"Unsupported char:'s' or 'r'\n");    
	   return (FALSE); 	
	}
	UART_CLOSE(fd); 
    close(listen_fd);    
	return 0;
}
  
/***********End Of File************/
