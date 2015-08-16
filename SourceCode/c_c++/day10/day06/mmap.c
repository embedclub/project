
#include "public.h"
#include <sys/mman.h>
struct Emp
{
	int id;
	char name[10];
	int age;
	double salary;
};

int main(void)
{
	int fd = open("emp.dat", 
				   O_RDWR|O_CREAT|O_TRUNC,
				   0666);
	//映射文件之前，要确保文件的大小足够使用
	ftruncate(fd, sizeof(struct Emp) * 10);
	//映射文件,使文件中任意一个字节对应一个虚拟地址
	void *p = mmap(0, //首地址由操作系统指定
				   sizeof(struct Emp) * 10,
				   PROT_READ|PROT_WRITE,//读写
				   //MAP_PRIVATE,
				   MAP_SHARED,
				   fd, //映射哪个文件	
				   0// 从文件的第几个字节开始映射
					);
	if(p == MAP_FAILED)
	{
		perror("映射失败");
		return -1;
	}
	struct Emp *pe = p;
	/*向文件中写入内容*/
	pe[0].id = 100;
	// char *name; pe[0].name = "张三";
	//char name[10]
	strcpy(pe[0].name , "张三");	
	pe[0].age = 30;
	pe[0].salary = 10000.01;
    /*....*/

	
	munmap(p, sizeof(struct Emp)*10);
	close(fd);
	fd = open("emp.dat", O_RDONLY);
	struct Emp test = {0};
	read(fd, &test, sizeof(struct Emp));
	printf("name = %s, age = %d, salary=%lf\n",
			test.name,
			test.age,
			test.salary);	
	return 0;	
}



