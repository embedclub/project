/*
    动态分配内存练习
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int x, y;
} pt;
int main() {
    pt *p_pt = (pt *)malloc(3 * sizeof(pt));
    if (p_pt) {
        printf("请输入第一个点的位置：");
        scanf("%d%d", &(p_pt->y), &(p_pt->x));
        printf("请输入第二个点的位置：");
        scanf("%d%d", &((p_pt + 1)->y), &((p_pt + 1)->x));
        (p_pt + 2)->x = (p_pt->x + (p_pt + 1)->x) / 2;
        (p_pt + 2)->y = (p_pt->y + (p_pt + 1)->y) / 2;
        printf("中点位置在(%d, %d)\n", (p_pt + 2)->y, (p_pt + 2)->x);
        free(p_pt);
        p_pt = NULL;
    }
    return 0;
}




