#include <stdio.h>
#include <stdlib.h>

int i1 = 10; //数据段
int i2 = 20; //数据段
int i3;	//bss段
static int i4 = 40; //数据段
const  int i5 = 50; //代码段
void fa(int i6)  //栈
{
//	int *test = (int *)&i5;
//	*test = 1000;
	int i7 = 70; //栈
	static int i8 = 80; //数据段
	const int i9 = 90; // 栈 
//	int *test = (int *)&i9;
//	*test = 1000;
	int *pi = malloc(16); //16个字节在堆区
                          //pi 在栈中
	char *str1 = "abcdef"; //str所使用4字节 栈
						//"abcdef"在代码段中
	char str2[] = "abcdef";//str2 7个字节在哪？栈
                         //"abcdef"在代码段中
	printf("i6 addr=%p\n", &i6);
	printf("i7 addr=%p\n", &i7);
	printf("i8 addr=%p\n", &i8);
	printf("i9 addr=%p\n", &i9);
	printf("malloc addr=%p\n", pi);
	printf("pi addr=%p\n", &pi);
	printf("str1 addr=%p, abcef addr=%p\n",
			&str1, str1);
	printf("str2 addr=%p\n", str2);
}


int main()
{
	printf("i1 addr=%p\n", &i1);		
	printf("i2 addr=%p\n", &i2);		
	printf("i3 addr=%p\n", &i3);		
	printf("i4 addr=%p\n", &i4);		
	printf("i5 addr=%p\n", &i5);		
	fa(100);
	while(1);
	return 0;
}





