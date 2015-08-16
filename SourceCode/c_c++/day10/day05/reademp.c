#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
  int fd = open("emp.txt",O_RDONLY);
  if(fd==-1) perror("open"),exit(-1);
  int id;
  char name[20] = {};
  int age;
  double sal;
  read(fd,&id,4);
  read(fd,name,9);
  read(fd,&age,4);
  read(fd,&sal,sizeof(sal));
  printf("id=%d,name=%s,age=%d,sal=%.2lf\n",
	id,name,age,sal);
  struct Emp{
    int id;
	char name[20];
    int age;
	double sal;
  } emp1;
  read(fd,&emp1,sizeof(emp1));
  printf("id=%d,name=%s,age=%d,sal=%.2lf\n",
	emp1.id,emp1.name,emp1.age,emp1.sal);
  close(fd);
}

