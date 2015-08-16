/*
    函数指针演示
*/
#include <stdio.h>
int add(int x, int y) {
    return x + y;
}
int main() {
    int (*p_func)(int, int) = NULL;
    p_func = add;
    printf("计算结果是%d\n", p_func(3, 7));
    printf("计算结果是%d\n", (*p_func)(3, 7));
    return 0;
}



