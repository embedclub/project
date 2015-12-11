/*
    指针和数组演示
	数组名是个静态的指针常量哈
*/
#include <stdio.h>
int main() {
    int arr[] = {1, 2, 3, 4, 5}, num = 0;
    int *p_num = arr;
    for (num = 0;num <= 4;num++) {
        printf("%d ", arr[num]);
        printf("%d ", p_num[num]);
        printf("%d ", *(arr + num));
        printf("%d ", *(p_num + num));
    }
    printf("\n");
    for (p_num = arr;p_num <= arr + 4;p_num++) {
        printf("%d ", *p_num);
    }
    printf("\n");
    return 0;
}
