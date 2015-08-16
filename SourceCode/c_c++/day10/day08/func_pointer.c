
#include "public.h"

void func(int num)
{
	printf("%d\n", num);
	return ;
}
typedef void (*new_type)(int);

int main()
{
	func(12);
	printf("func = %p\n", func);
	//void (*test)(int) = func;
	new_type test = func;
	test(15);
	return 0;
}

