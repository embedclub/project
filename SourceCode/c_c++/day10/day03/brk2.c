
#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main()
{
	void *p = sbrk(0);//记录初始位置
	int *pi = sbrk(sizeof(int));
	*pi = 100;
	double *pd = sbrk(sizeof(double));
	*pd = 3.14;
	char *str = sbrk(10);
	strcpy(str, "hello");
	printf("%d %lf %s\n", *pi, *pd, str);
	brk(p); // 释放所有空间
	return 0;
}



