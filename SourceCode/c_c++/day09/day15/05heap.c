/*
    动态内存演示
*/
#include <stdio.h>
#include <stdlib.h>
int main() {
    int size = 0, num = 0, *p_num = NULL;
    printf("请输入一个整数：");
    scanf("%d", &size);
    p_num = (int*)malloc(size * sizeof(int));
    if (p_num) {
        for (num = 0;num <= size - 1;num++) {
            printf("请输入一个整数：");
            scanf("%d", p_num + num);
        }
        for (num = size - 1;num >= 0;num--) {
            printf("%d ", *(p_num + num));
        }
        printf("\n");
        free(p_num);
        p_num = NULL;
    }
    return 0;
}



