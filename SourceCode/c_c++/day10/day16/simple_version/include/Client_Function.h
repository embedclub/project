#ifndef __SERVER_FUNCTION_H__
#define __SERVER_FUNCTION_H__

#include "Public_Head.h"

//信号处理
void sigFunc(int signum);

//录入用户信息
void Input_User();

//创建客户端连接
void Client_Create();

//负责接收消息的进程
void *Data_Recv(void *srg);

//负责发送消息的线程
void *Data_Send(void *srg);

void Pthread_Create();

//输出提示输入的部分
void print_self();

//输出其他人的话
void print_other(char *str);

//输出系统通告
void print_system(char *str);

//清除输入的昵称里面的回车
void Clear_Enter(char *str);


#endif
