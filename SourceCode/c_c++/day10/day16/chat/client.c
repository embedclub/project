//�����ҿͻ���
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <signal.h>
//׼������
int sockfd;//�ͻ���socket
char *IP = "127.0.0.1";//����IP
short PORT = 10222;//����������˿�
typedef struct sockaddr SA;
char name[30];//��������ǳ�
//1�����ͻ��ˣ����ӷ�����
void init(){
	printf("�ͻ��˿�ʼ����\n");
	sockfd = socket(PF_INET,SOCK_STREAM,0);
	struct sockaddr_in addr;
	addr.sin_family = PF_INET;
	addr.sin_port = htons(PORT);
	addr.sin_addr.s_addr = inet_addr(IP);
	if(connect(sockfd,(SA*)&addr,sizeof(addr)) == -1){
		perror("�޷����ӵ�������");
		printf("�ͻ�������ʧ��\n");
		exit(-1);
	}
	printf("�ͻ��������ɹ�\n");
}
//2ͨ��
void start(){
	//����Ϣ֮ǰ�������߳̽��ܷ���������������Ϣ
	pthread_t pid;
	void* recv_thread(void*);//��������
	pthread_create(&pid,0,recv_thread,0);
	while(1){
		char buf[100] = {};
		scanf("%s",buf);//��ȡ�ͻ��˵�����
		char msg[100] = {};
		sprintf(msg,"%s ˵: %s",name,buf);
		send(sockfd,msg,strlen(msg),0);//������Ϣ��������
	}
}
void* recv_thread(void *p){
	while(1){
		char buf[100] = {};
		if(recv(sockfd,buf,sizeof(buf),0)<=0){
			return;//����ͽ����߳�
		}
		printf("%s\n",buf);//������յ�������
	}
}
void sig_close(){
	//�رտͻ��˵�socket
	close(sockfd);
	exit(0);
}
int main(){
	signal(SIGINT,sig_close);//�ƺ���
	printf("�����������ǳ�:");
	scanf("%s",name);
	init();//���ӷ�����
	send(sockfd,name,strlen(name),0);
	start();//ͨ��
	return 0;
}
