/*
    点菜作业
*/
#include <stdio.h>
int main() {
    int order = 0;
    printf("请点菜：");
    scanf("%d", &order);
#ifdef   ZHAOBENSHAN
    if (order) {
        printf("这个菜真没有\n");
    }
    else {
        printf("这个菜没有\n");
    }
#else
    if (order) {
        printf("这个菜没有\n");
    }
    else {
        printf("这个菜有\n");
    }
#endif
    return 0;
}



