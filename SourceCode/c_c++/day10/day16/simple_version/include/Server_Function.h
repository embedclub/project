#ifndef __SERVER_FUNCTION_H__
#define __SERVER_FUNCTION_H__

#include "Public_Head.h"

void sigFunc(int signum);

void Server_Create();

pthread_t Deal_Client_Connect(int *clientfd);

void *Data_Interaction(void *srg);

void Send_Inform();

#endif
