
#include <stdio.h>
#include <sys/mman.h>
#include <string.h>

int main()
{
	/*映射一片物理内存*/
	void *p = mmap(
				   0,// 映射的首地址（虚拟地址）
					// 0代表由操作系统指定
				   1024,//按页对齐（不够一页补齐）
				   PROT_READ|PROT_WRITE,//权限
				   MAP_PRIVATE|MAP_ANONYMOUS,
				   0,
				   0);
	if(p == MAP_FAILED)
	{
		perror("mmap failed");
		return -1;
	}
	int *pi = p;
	*pi = 123;
	char *buf = p +4;
	strcpy(buf, "helloworld");

	printf("address mmap %p\n", p);
	getchar();
	/*释放内存*/
	munmap(p, 1024);
	return 0;
}



