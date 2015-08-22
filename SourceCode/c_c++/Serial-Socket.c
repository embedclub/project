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
#include<stdio.h>      		/*��׼�����������*/
#include<stdlib.h>     		/*��׼�����ⶨ��*/
#include<unistd.h>     		/*Unix��׼��������*/
#include<sys/types.h> 
#include<sys/stat.h>   
#include<fcntl.h>      		/*�ļ����ƶ���*/
#include<termios.h>    		/*PSIX �ն˿��ƶ���*/
#include<errno.h>     		/*����Ŷ���*/
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
* ���ƣ�           		UART_OPEN
* ���ܣ�           	�򿪴��ڲ����ش����豸�ļ�����
* ��ڲ�����       	fd	:�ļ�������     
			port 	:���ں�(ttySAC1,ttySAC2)
* ���ڲ�����       	��ȷ����Ϊ1�����󷵻�Ϊ0
*******************************************************************/
int UART_OPEN(int fd,char* port)
{
	fd = open( port, O_RDWR|O_NOCTTY|O_NONBLOCK);

	if (FALSE == fd){
		perror("Can't Open Serial Port");
		return(FALSE);
	}                          

	if(fcntl(fd, F_SETFL, 0) < 0){				//�ָ�����Ϊ����״̬  
		printf("fcntl failed!\n");
		return(FALSE);
	}     


	if(0 == isatty(fd)){						//�����Ƿ�Ϊ�ն��豸 Parm:STDIN_FILENO
		printf("This is not a terminal device\n");
		return(FALSE);
	}	              
	printf("!!OPEN ttyS* SUCCESS!....\n");
	return fd;
}

/*******************************************************************
* ���ƣ�            UART_CLOSE
* ���ܣ�            �رմ��ڲ����ش����豸�ļ�����
* ��ڲ�����        fd:�ļ�������     port :���ں�(ttySAC1,ttySAC2)
* ���ڲ�����        void
*******************************************************************/
void UART_CLOSE(int fd)
{
    close(fd);
}
 
/*******************************************************************
* ���ƣ�            	UART_CONFIG
* ���ܣ�            ���ô�������λ��ֹͣλ��Ч��λ
* ��ڲ�����        fd 			:�����ļ�������
*                   speed     	:�����ٶ�
*                   flow_ctrl  	:����������
*                   databits   	:����λ   ȡֵΪ 7 ����8
*                   stopbits   	:ֹͣλ   ȡֵΪ 1 ����2
*                   parity     	:Ч������ ȡֵΪN,E,O,,S
*���ڲ�����         ��ȷ����Ϊ1�����󷵻�Ϊ0
*******************************************************************/
int UART_CONFIG(int fd,int speed,int flow_ctrl,int databits,int stopbits,int parity)
{
   
	int   i;
	int   status;
	speed_t  speed_arr; 
    struct   termios new_options,old_options;
   
	/****tcgetattr(fd,&options)�õ���fdָ��������ز������������Ǳ�����options,
	�ú��������Բ��������Ƿ���ȷ���ô����Ƿ���õȡ������óɹ�����������ֵΪ0��
	������ʧ�ܣ���������ֵΪ1.	****/
	if  ( tcgetattr( fd,&old_options)  !=  0){
		perror("tcgetattr\n");    
		return(FALSE); 
	}
	memset(&new_options,0,sizeof(new_options));
	new_options=old_options;
	new_options.c_cflag |= CLOCAL |CREAD;		//����غͽ���
	new_options.c_cflag &= ~CSIZE;				//����������־λ
	//ѡ�񴮿�ģʽ:�淶ģʽ+�ǹ淶ģʽ+ԭʼģʽ
	
	//���ô������벨���ʺ����������
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
  
	switch(flow_ctrl)			//��������������
	{
	case 0 :			//��ʹ��������
		new_options.c_cflag &= ~CRTSCTS;
		break;   
	case 1 :			//ʹ��Ӳ��������
		new_options.c_cflag |= CRTSCTS;
		break;
	case 2 :			//ʹ�����������
		new_options.c_cflag |= IXON | IXOFF | IXANY;
		break;
	}

	switch (databits)		//��������λ
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
  
	switch (parity)		  //����У��λ
	{  
	case 'n':
	case 'N': 		//����żУ��λ��
		new_options.c_cflag &= ~PARENB; 
		new_options.c_iflag &= ~INPCK;    
		break; 
	case 'o':  
	case 'O':		//����Ϊ��У��    
		new_options.c_cflag |= (PARODD | PARENB); 
		new_options.c_iflag |= INPCK;             
		break; 
	case 'e': 
	case 'E':		//����ΪżУ��  
		new_options.c_cflag |= PARENB;       
		new_options.c_cflag &= ~PARODD;       
		new_options.c_iflag |= INPCK;      
	    break;
	case 's':
	case 'S': 		//����Ϊ�ո� 
		new_options.c_cflag &= ~PARENB;
		new_options.c_cflag &= ~CSTOPB;
		break; 
	default:  
		perror("parity\n");    
		return (FALSE); 
	} 

	switch (stopbits)			// ����ֹͣλ 
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
//	options.c_oflag &= ~OPOST;		  //�޸����ģʽ��ԭʼ�������
//	options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);//�Ҽӵ�
//	options.c_lflag &= ~(ISIG | ICANON);
	new_options.c_lflag |= (ICANON | ECHO | ECHOE | IEXTEN);
   
	//���õȴ�ʱ�����С�����ַ�
// 	options.c_cc[VTIME] = 1; /* ��ȡһ���ַ��ȴ�1*(1/10)s */  
// 	options.c_cc[VMIN] = 1; /* ��ȡ�ַ������ٸ���Ϊ1 */
	
	//�����������������������ݣ����ǲ��ٶ�ȡ ˢ���յ������ݵ��ǲ���
	tcflush(fd,TCIFLUSH);
	
	//�������� (���޸ĺ��termios�������õ������У�
	if (tcsetattr(fd,TCSANOW,&new_options) != 0)  {
		perror("tcsetattr\n");  
		return (FALSE); 
	}
	return (TRUE); 
}

/*******************************************************************
* ���ƣ�                UART_DEFAULT()
* ���ܣ�                ���ڳ�ʼ��
* ��ڲ�����    fd       	:�ļ�������   
*               speed  	 	:�����ٶ�
*               flow_ctrl 	:����������
*               databits  	:����λ   ȡֵΪ 7 ����8
*               stopbits  	:ֹͣλ   ȡֵΪ 1 ����2
*               parity    	:Ч������ ȡֵΪN,E,O,,S
*                      
* ���ڲ�����        ��ȷ����Ϊ1�����󷵻�Ϊ0
*******************************************************************/
int UART_DEFAULT(int fd)
{
	if (UART_CONFIG(fd,115200,0,8,1,'N') == FALSE)		//���ô�������֡��ʽ                                                      
		return FALSE;
	else
		return  TRUE;
}
 
/*******************************************************************
* ���ƣ�                  UART_RECV
* ���ܣ�                ���մ�������
* ��ڲ�����        fd 			:�ļ�������    
*                   rcv_buf     	:���մ��������ݴ���rcv_buf��������
*                   data_len    	:һ֡���ݵĳ���
* ���ڲ�����        ��ȷ����Ϊ1�����󷵻�Ϊ0
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
	
	fs_sel = select(fd+1,&fs_read,NULL,NULL,&time);			//ʹ��selectʵ�ִ��ڵĶ�·ͨ��
	if(fs_sel && FD_ISSET(fd,&fs_read))
	{
		len = read(fd,rcv_buf,data_len);
		return len;
	}
	else
		return FALSE;    
}

/********************************************************************
* ���ƣ�                  UART_SEND
* ���ܣ�                  ��������
* ��ڲ�����        fd  		:�ļ�������    
*                   send_buf    	:��Ŵ��ڷ�������
*                   data_len    	:һ֡���ݵĸ���
* ���ڲ�����        ��ȷ����Ϊlen�����󷵻�Ϊ0
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
 
 /*��������*/
int main(int argc, char **argv)
{
	int fd;                            		//�ļ�������
	int err;                          	 	//���ص��ú�����״̬
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
	fd = UART_OPEN(fd,argv[1]);		 //�򿪴��ڣ������ļ�������
	
	do{
		err = UART_DEFAULT(fd);
	}while(FALSE == err || FALSE == fd);
	printf("Port is READY!\n");
	
	if((listen_fd=socket(AF_INET,SOCK_STREAM,0))<0)		//����socket
  	{
        printf("Socket Error:%s\n\a",strerror(errno));
		return FALSE;
  	}
	bzero(&client_addr,sizeof(struct sockaddr_in));
 	client_addr.sin_family=AF_INET;
 	client_addr.sin_port=htons(MY_PORT);
 	client_addr.sin_addr.s_addr=htonl(INADDR_ANY);
 	n=1;
 	setsockopt(listen_fd,SOL_SOCKET,SO_REUSEADDR,&n,sizeof(int)); //�����������ֹ��,���������Եڶ��ο������������õȴ�һ��ʱ��
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
		while (1) 					//ѭ����ȡ����
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
				/* �ӽ��̴���ͻ��˵����� */
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
