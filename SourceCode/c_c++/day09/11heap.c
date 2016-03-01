/*
    动态分配内存练习
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int x, y;
} pt;
pt *midpt(const pt *p_pt1, const pt *p_pt2, pt *pp_pt) {
    pp_pt = (pt*)malloc(sizeof(pt));
    if (pp_pt) {
        (pp_pt)->x = (p_pt1->x + p_pt2->x) / 2;
        (pp_pt)->y = (p_pt1->y + p_pt2->y) / 2;
    }
    return pp_pt;
}
int main() {
    pt pt1 = {}, pt2 = {}, *p_pt = NULL;
    printf("请输入一个点的位置：");
    scanf("%d%d", &(pt1.y), &(pt1.x));
    printf("请输入一个点的位置：");
    scanf("%d%d", &(pt2.y), &(pt2.x));
    midpt(&pt1, &pt2, p_pt);
    if (p_pt) {
        printf("中点位置是(%d, %d)\n", p_pt->y, p_pt->x);
        free(p_pt);
        p_pt = NULL;
    }
    return 0;
}




