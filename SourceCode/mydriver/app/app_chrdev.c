#include <stdio.h>  
#include <fcntl.h>  
#include <unistd.h>
  
int main(void)  
{  
    int fd;  
    int i;    
    char buf[50];  
  
    fd = open("/dev/chrdev",O_RDWR);  
    if(fd < 0){  
        printf("can't open dev\n");  
        return -1;  
    }  
  
    read(fd,buf,11);  
      
    printf("%s",buf);  
  
    return 0;  
}  


