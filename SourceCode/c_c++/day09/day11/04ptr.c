/*
    指针计算规则演示
*/
#include <stdio.h>
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int num = 0;
    int *p_num = &num, *p_num1 = NULL;
    printf("p_num是%p,p_num + 3是%p\n", p_num, p_num + 3);
    printf("p_num是%p,p_num - 3是%p\n", p_num, p_num - 3);
    p_num = &arr[1];
    p_num1 = &arr[4];
    printf("p_num1 - p_num是%d\n", p_num1 - p_num);
    return 0;
}





