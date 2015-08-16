//�����ҷ�������
#include <stdio.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
//һЩ׼������
struct client{
	char name[30];//�ͻ�����������ʱ��������������
	int fds;//��־�ͻ��˵�socket������
};
struct client c[100] = {0};//����¼100���ͻ���
int sockfd;//��������socket
int size;//���������±�
char *IP = "127.0.0.1";//��ȡ����IP�����͵�ַ
short PORT = 10222;//�˿ں�
typedef struct sockaddr SA;//����ͨ�ŵ�ַ����ת��

//1��ʼ��������������
void init(){
	printf("�����ҷ�������ʼ����..\n");
	//����socket
	sockfd = socket(PF_INET,SOCK_STREAM,0);
	if(sockfd == -1){
		perror("����socketʧ��");
		printf("����������ʧ��\n");
		exit(-1);
	}
	//׼��ͨ�ŵ�ַ
	struct sockaddr_in addr;//����ͨ�ŵ�ַ�ṹ
	addr.sin_family = PF_INET;//Э���
	addr.sin_port = htons(PORT);//�˿�
	addr.sin_addr.s_addr = inet_addr(IP);//IP��ַ
	//��socket��ͨ�ŵ�ַ
	if(bind(sockfd,(SA*)&addr,sizeof(addr)) == -1){
		perror("��ʧ��");
		printf("����������ʧ��\n");
		exit(-1);
	}
	printf("�ɹ���\n");
	//���ü���
	if(listen(sockfd,100) == -1){
		perror("���ü���ʧ��");
		printf("����������ʧ��\n");
		exit(-1);
	}
	printf("���ü����ɹ�\n");
	printf("��ʼ���������ɹ�\n");
	//�ȴ��ͻ�������(д����һ��������)
}
//�ַ���Ϣ����
void sendMsgToAll(char *msg){
	int i = 0;
	for(;i<size;i++){
		printf("sendto%d\n",c[i].fds);
		send(c[i].fds,msg,strlen(msg),0);
	}
}
//�̺߳����н���ͨ��
//��Ҫ�ǽ��ܿͻ��˵���Ϣ������Ϣ�ַ������пͻ���
void * service_thread(void *p){
	char name[30] = {};
	if(recv(c[size].fds,name,sizeof(name),0)>0){
		//���յ��ͻ��˵��ǳ�
		strcpy(c[size].name,name);
	}
	size++;
	//��Ⱥ��һ����ʾ���������пͻ���ĳĳ����������
	char tishi[100] = {};
	sprintf(tishi,"���һ�ӭ %s ���뱾������\n",c[size-1].name);
	//����Ⱥ����Ϣ�ĺ���
	sendMsgToAll(tishi);
	int fd = *(int*)p;
	printf("pthread = %d\n",fd);
	//ͨ�ţ�������Ϣ���ַ���Ϣ
	while(1){
		char buf[100] = {};
		if(recv(fd,buf,sizeof(buf),0) == 0){
			//����0��ʾ�ͻ����˳�����
			printf("fd = %dquit\n",fd);//test
			//�������ͻ����������е���Ϣ
			int i,j;
			char name[20] = {};
			int flag = 1;//���ر�־
			for(i=0;i<size;i++){
				if(c[i].fds == fd){
					strcpy(name,c[i].name);//��¼Ҫɾ���ͻ��˵��ǳ�
					i++;//��ֹ�������
					flag = 0;
				}
				if(flag!=1){
					c[i-1].fds = c[i].fds;//����
					strcpy(c[i-1].name,c[i].name);
				}
			}
			c[i].fds = 0;//�������һ������Ԫ��ֵ
			strcpy(c[i].name,"");//���鸳ֵ�մ�
			size--;
			printf("quit->fd=%dquit\n",fd);
			char msg[100] = {};
			sprintf(msg,"���� %s �뿪��������\n",name);
			//���˳���ʾ���͸�������
			sendMsgToAll(msg);
			close(fd);//�ر�������
			return;//�ͻ����˳�֮�󣬽����߳�
		}
		sendMsgToAll(buf);//�����ȷ��ȡ���ͻ��˷�������Ϣ��ֱ�ӽ���Ϣ�ַ����������߿ͻ�����
	}
}
//2�ȴ��ͻ������ӣ������������ķ���
void service(){
	printf("��������ʼ����\n");
	while(1){
		struct sockaddr_in fromaddr;//�洢�ͻ��˵�ͨ�ŵ�ַ
		socklen_t len = sizeof(fromaddr);
		int fd = accept(sockfd,(SA*)&fromaddr,&len);
		if(fd == -1){
			printf("�ͻ������ӳ���\n");
			continue;//������һ��ѭ���ȴ��ͻ�������
		}
		//�пͻ��˳ɹ����Ϸ���������¼socket
		c[size].fds = fd;
		printf("fd = %d\n",fd);//���Բ鿴
		//�����̣߳�Ϊ�˿ͻ��˷���
		pthread_t pid;
		pthread_create(&pid,0,service_thread,&fd);
	}
}
void sig_close(){
	//�رշ�������socket
	close(sockfd);
	printf("�������Ѿ��ر�..\n");
	exit(0);
}
int main(){
	//��CTRL+C �����źŽ��д��������ƺ���
	//�رշ�������socket��������
	signal(SIGINT,sig_close);//�Զ����źŴ�����
	init();//��ʼ������������
	service();//��������
	return 0;
}







