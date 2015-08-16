

#include "public.h"
struct test
{
	int age;
	char name[256];
	double salary;
};
int main()
{
	struct test s1;
	s1.age = 100;
	strcpy(s1.name, "abc");
	s1.salary = 8000.01;
//	char buf[1024] = {0};
//	sprintf(buf, "%d %s %lf", s1.age, s1.name,
//			s1.salary);
	//printf("buf = %s\n", buf);
	int fd = open("data.txt", 
					O_RDWR|O_CREAT|O_TRUNC,
                   0644);
	//write(fd, &s1, sizeof(s1));
	  write(fd, &s1.age, sizeof(int));
	  write(fd, s1.name, sizeof(s1.name));
	  write(fd, s1.salary, sizeof(s1.salary));
	//write(fd, buf, sizeof(buf));
	//将buf缓冲区清空为0
#if 0
	memset(buf, 0, sizeof(buf));
	lseek(fd, 0, SEEK_SET);
	read(fd, buf, sizeof(buf));
	printf("buf = %s\n", buf);
	struct test s2;
    sscanf(buf, "%d %s %lf", &s2.age,
			s2.name,
			&s2.salary);
	printf("s2.salary= %lf\n", s2.salary);
	s2.salary += 1000;
#endif
	struct test s2;
	lseek(fd, 0, SEEK_SET);
	read(fd, &s2, sizeof(s2));
	printf("s2.salary = %lf\n", s2.salary);
	return 0;

}
