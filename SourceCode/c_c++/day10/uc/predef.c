
#include <stdio.h>

void abc()
{
	printf("__FILE__:%s\n", __FILE__);
	printf("__LINE__:%d\n", __LINE__);
	printf("in abc() __func__:%s\n", __func__);
}

int main()
{
	printf("in main() __func__:%s\n", __func__);
	abc();
}


