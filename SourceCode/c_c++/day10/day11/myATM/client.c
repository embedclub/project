/* 客户端*/
#include <stdio.h>
#include "bank.h"
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <string.h>

static int msgid1;//定义两个接受消息队列的id的变量
static int msgid2;
//获取消息队列函数,
void getID(){
	msgid1 = msgget(key1,0);
	if(msgid1 == -1){
		perror("获取消息队列1失败");
		exit(-1);
	}
	msgid2 = msgget(key2,0);
	if(msgid2 == -1){
		perror("获取消息队列2失败");
		exit(-1);
	}
}
//开户函数
void createUser(){
	struct Account acc;
	printf("请输入用户名:\n");
	scanf("%s",acc.name);
	printf("请输入密码:\n");
	scanf("%s",acc.password);
	printf("请输入金额:\n");
	scanf("%d",&acc.balance);
	struct Msg msg = {M_OPEN,acc};
	//获取消息队列
	getID();
	//将消息发送到消息队列1中
	msgsnd(msgid1,&msg,sizeof(msg.acc),0);
	//接受消息队列2中的消息
	msgrcv(msgid2,&msg,sizeof(msg.acc),0,0);
	if(msg.mtype == M_SUCCESS){
		printf("开户成功！\n");
	}
	else{
		printf("开户失败！\n");
	}
}
//销户
void destroyUser(){}
//存钱
void saveMoney(){}
//取钱
void getMoney(){}
//查询
void checkMoney(){}
//转账
void moveMoney(){}

//客户端界面
void mainPage(){
	while(1){
		printf("  欢迎使用迷你ATM机\n");
		printf("---------------------\n");
		printf("[1] 开户");
		printf("      [2] 销户\n");
		printf("[3] 存钱");
		printf("      [4] 取钱\n");
		printf("[5] 查询");
		printf("      [6] 转账\n");
		printf("[0] 退出\n");
		printf("---------------------\n");
		printf("请选择:\n");
		int num = 0;
		scanf("%d",&num);
		switch(num){
			case 1:createUser();break;
			case 2:destroyUser();break;
			case 3:saveMoney();break;
			case 4:getMoney();break;
			case 5:checkMoney();break;
			case 6:moveMoney();break;
			case 0:printf("谢谢使用，再见！\n");return ;
			default:printf("输入错误\n");
		}
	}
}
int main(){
	mainPage();
	return 0;
}
