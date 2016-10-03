#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <unistd.h>  
#include <fcntl.h>  
#include <signal.h>  
#include <limits.h>  
#include <termios.h>  
#include <errno.h>  
#include <linux/input.h>  
  
#define TOUCHKEY_TAG             "TouchkeyDemo "  
#define TOUCHKEY_FILE            "/dev/input/event5"  
  
  
int main(int argc, char **argv)  
{  
    int nFd;  
    int nRet;  
    struct input_event *sInputEvent;  
  
      
    sInputEvent = malloc(sizeof(struct input_event));  
    nFd = open(TOUCHKEY_FILE, O_RDWR);  
    if(nFd < 0)  
    {  
        printf("open failed!\n");
        return -1;  
    }  
    else  
    {  
        printf("open file %s success.", TOUCHKEY_FILE);  
    }  
  
    memset(sInputEvent, 0, sizeof(struct input_event));  
    nRet = read(nFd, sInputEvent, sizeof(struct input_event));  
    if(nRet < 0)  
    {  
        printf("read file %s error.");  
        return nRet;  
    }  
  
    printf("type: 0x%x ", sInputEvent->type);  
    printf("code: 0x%x ", sInputEvent->code);  
    printf("value: 0x%x", sInputEvent->value);  
  
    free(sInputEvent);  
    close(nFd);  
    return 0;  
}  
