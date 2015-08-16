
#include "public.h"
#include <sys/stat.h>
#include <time.h>

int main()
{
	struct stat s ;//准备了存储文件属性的空间
    //struct stats *s;//定义了一个指针，有问题
	stat("a.txt", &s);//s结构体会被填充满
	
	printf("inode = %d\n", (int)s.st_ino);
	printf("权限 = %#o\n", s.st_mode & 0777);
	printf("文件大小=%d\n", (int)s.st_size);
	printf("文件的最后修改时间:%s\n", 
			ctime(&(s.st_mtime)));
	if(S_ISREG(s.st_mode))
	{
		printf("普通文件\n");
	}
	else if(S_ISDIR(s.st_mode))
	{
		printf("目录文件\n");
	}
	else if(S_ISLNK(s.st_mode))
	{
		printf("软链接文件\n");
	}
	return 0;
}


