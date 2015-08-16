/*
    指针类型返回值演示
*/
#include <stdio.h>
int *neg(int *p_num, int size) {
    int num = 0;
    for (num = 0;num <= size - 1;num++) {
        *(p_num + num) = 0 - *(p_num + num);
    }
    return p_num;
}
int main() {
    int arr[] = {1, 2, 3, 4, 5}, num = 0;
    int *p_num = neg(arr, 5);
    for (num = 0;num <= 4;num++) {
        printf("%d ", *(p_num + num));
    }
    printf("\n");
    return 0;
}


