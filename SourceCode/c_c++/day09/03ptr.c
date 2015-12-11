/*
    指针大小演示
	void类型的指针使用非常重要，需要留意它的使用技巧哈
	学会类比哈^~^
*/
#include <stdio.h>
int main() {
    int num = 300;
    char ch = 0;
    int *p_num = &num;
    char *p_ch = &num;
    void *p_void = &num;
    p_void = &ch;
    printf("sizeof(p_num)是%d,sizeof(p_ch)是%d\n", sizeof(p_num), sizeof(p_ch));
    printf("*p_num是%d\n", *p_num);
    printf("*(char*)p_num是%d\n", *(char*)p_num);
    printf("*p_ch是%d\n", *p_ch);
    *(char*)p_void = 10;
    printf("*p_void是%d\n", *(char*)p_void);//注意void指针的使用哈
    return 0;
}




