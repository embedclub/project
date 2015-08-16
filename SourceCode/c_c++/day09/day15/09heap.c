/*
    动态分配内存练习
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int x, y;
} pt;
/*pt *read(void) {
    pt *p_pt = (pt *)malloc(sizeof(pt));
    if (p_pt) {
        printf("请输入点的位置：");
        scanf("%d%d", &(p_pt->y), &(p_pt->x));
    }
    return p_pt;
}*/
void read(pt **pp_pt) {
    *pp_pt = (pt*)malloc(sizeof(pt));
    if (*pp_pt) {
        printf("请输入点的位置：");
        scanf("%d%d", &((*pp_pt)->y), &((*pp_pt)->x));
    }
}
int main() {
    //pt *p_pt = read();
    pt *p_pt = NULL;
    read(&p_pt);
    if (p_pt) {
        printf("点的位置是(%d, %d)\n", p_pt->y, p_pt->x);
        free(p_pt);
        p_pt = NULL;
    }
    return 0;
}



