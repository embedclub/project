/*
    结构体练习
*/
#include <stdio.h>
typedef struct {
    int x, y;
} pt;
pt *read(pt *p_pt) {
    printf("请输入一个点的位置：");
    scanf("%d%d", &(p_pt->y), &(p_pt->x));
    return p_pt;
}
void print(const pt *p_pt) {
    printf("点的位置是(%d, %d)\n", p_pt->y, p_pt->x);
}
int main() {
    pt pt1 = {};
    pt *p_pt = read(&pt1);
    print(&pt1);
    print(p_pt);
    return 0;
}

