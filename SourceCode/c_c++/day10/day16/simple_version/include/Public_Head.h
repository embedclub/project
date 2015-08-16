/*
 * 公用头文件
 */

#ifndef __PUBLIC_HEAD_H__
#define __PUBLIC_HEAD_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8188
#define MAX_CLIENT 10

typedef struct 
{
	char m_name[20];
	char m_pwd[20];
	char m_speck[256];
} USER;


#endif
