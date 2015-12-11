/*
    const指针演示
*/
#include <stdio.h>
int main() {
    int num = 0;
	int a = 10;
    const int *p_num = &num;//指针指向可以更改哈
    int * const p_num1 = &num;//指针指向是定死的，但是指针指向的变量内容可以更改哈
    
	
	//p_num = a;     错误
    //p_num = NULL;

	p_num = &a;
	*p_num1 = 10;
    //p_num1 = NULL;
    return 0;
}
