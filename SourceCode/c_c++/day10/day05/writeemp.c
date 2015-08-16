#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main(){
 int fd=open("emp.txt",O_RDWR|O_CREAT|O_TRUNC,0666);
  if(fd == -1) perror("open"),exit(-1);
  int id = 100;
  char *name = "zhangfei";
  int age = 1850;
  double sal = 120000;
  write(fd,&id,sizeof(id));
  write(fd,name,strlen(name)+1);//'\0'
  write(fd,&age,sizeof(age));
  write(fd,&sal,sizeof(sal));
  struct Emp{
    int id;
	char name[20];
	int age;
    double sal;
  };
  struct Emp emp = {200,"guanyu",1851,150000};
  write(fd,&emp,sizeof(emp));
  close(fd);
  return 0;
}

