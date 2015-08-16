/*
    指针大小演示
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
    return 0;
}




