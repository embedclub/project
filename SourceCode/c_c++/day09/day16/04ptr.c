/*
    函数参数演示
*/
#include <stdio.h>
void neg(int *p_num, int *p_val) {
    *p_num = 0 - *p_num;
}
void print(int *p_num, int *p_val) {
    printf("%d ", *p_num);
}
void sum(int *p_num, int *p_sum) {
    *p_sum += *p_num;
}
void for_each(int *p_num, int size, void (*p_func)(int*, int*), int *p_val) {
    int num = 0;
    for (num = 0;num <= size - 1;num++) {
        p_func(p_num + num, p_val);
    }
}
int main() {
    int res = 0;
    int arr[] = {1, 2, 3, 4, 5};
    for_each(arr, 5, print, NULL);
    printf("\n");
    for_each(arr, 5, neg, NULL);
    for_each(arr, 5, print, NULL);
    printf("\n");
    for_each(arr, 5, sum, &res);
    printf("求和结果是%d\n", res);
    return 0;
}
