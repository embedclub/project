
#ifndef __PUBLIC_H__
#define __PUBLIC_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

#define QUEUE_KEY 0x123456
struct MSG
{
	long mtype; //消息类型
	char buf[256];//消息有效数据
};




#endif


