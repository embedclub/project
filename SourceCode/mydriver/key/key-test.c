#include <stdio.h>  
#include <string.h>  
#include <unistd.h>  
#include <linux/input.h>  
#include <sys/ioctl.h>  
#include <stdlib.h>  
#include <fcntl.h>  
#include <sys/select.h>  
#include <sys/io.h>  
  
#include <linux/input.h>  
  
  
  
int main(int argc, char **argv)  
{  
    int fd, ret;  
    char *str;  
  
    struct input_event button_event;  
  
    fd = open("/dev/input/event5", O_RDWR);  
    if(fd< 0 ){  
        printf("open wrong\n");  
        return -1;  
    }  
      
    while(1)  
    {  
        ret = read(fd, &button_event, sizeof(button_event));  
        if(ret < sizeof(button_event)){  
            printf("incomplete read\n");  
            return -1;  
        }  
        switch(button_event.type){  
            case EV_KEY:  
                    str = "key";  
                    break;  
            case EV_SYN:  
                    str = "syn";  
                    break;  
            default:  
                    break;  
        }  
        printf("type = %s, code = %d\n", str, button_event.code);  
    }  
      
    close(fd);  
}  
