/*开户*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "bank.h"
int main(){
	int msgid1 = msgget(key1,0);
	if(msgid1 == -1){
		perror("获取消息队列1失败");
		printf("服务器启动失败");
		exit(-1);
	}
	int msgid2 = msgget(key2,0);
	if(msgid2 == -1){
		perror("获取消息队列2失败");
		printf("服务器启动失败");
		exit(-1);
	}
	//获取到消息队列之后，开始接受消息
	while(1){
		struct Msg msg;//存储消息信息的结构体
		struct Account accMove,accResult;//存储帐户信息
		//首先从客户那里收取消息队列1的信息 msgrcv 函数
		if(msgrcv(msgid1,&msg,sizeof(msg.acc),0,0) <=0 ){
			break;
		}
		//如果接受到了消息,根据消息的不同类型进行不同的操作
		if(msg.mtype == M_OPEN){//如果类型是开户
			int id = generator_id();
			accMove = msg.acc;
			accMove.id = id;
			if(createUser(accMove)==-1){
				printf("开户失败");
				msg.mtype = M_FAILED;//将消息类型置成失败
			}
			else{
				printf("开户成功");
				msg.mtype = M_SUCCESS;
			}
			msgsnd(msgid2,&msg,sizeof(msg.acc),0);//将消息由消息队列2发送给客户端
			//执行开户的操作
			//给用户分配帐号，将用户信息记录在文件中。
		}
		//最后把消息发过去，这时候消息的类型应该是两种情况M_SUCESS
		//或者是M_FAILED 
		else if(msg.mtype == M_DESTROY){}
		else if(msg.mtype == M_SAVE){}
		else if(msg.mtype == M_TAKE){}
		else if(msg.mtype == M_QUERY){}
		else if(msg.mtype == M_TRANSF){}
	}
	return 0;
}
