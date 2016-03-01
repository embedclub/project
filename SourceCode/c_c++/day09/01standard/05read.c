#include <stdio.h>
#include "05read.h"
int read(void) {
    int num = 0;
    printf("请输入一个数字：");
    scanf("%d", &num);
    return num;
}
