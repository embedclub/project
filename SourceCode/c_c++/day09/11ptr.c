/*
    指针演示
*/
#include <stdio.h>
int main() {
    int num = 0;
    //int *p_num = NULL;
    int *p_num = &num;
    p_num = &num;
    *p_num = 10;
    printf("num是%d\n", num);
    return 0;
}
