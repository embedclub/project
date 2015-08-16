//函数的形参列表为空时在C中的效果
#include <stdio.h>


int main(void)
{
	fn(/*66,3.14,"hello"*/);
	return 0;
}

//有void表示不接受实参，没有void则接受实参
int fn(void)
{
	printf("调用fn函数了\n");
}
