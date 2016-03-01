/*
    结构体练习
*/
#include <stdio.h>
typedef struct {
    int x, y;
} pt;
pt midpt(pt pt1, pt pt2) {
    pt mid = {};
    mid.y = (pt1.y + pt2.y) / 2;
    mid.x = (pt1.x + pt2.x) / 2;
    return mid;
}
pt *midpt(const pt *p_pt1, const pt *p_pt2, pt *p_mid) {
    p_mid->y = (p_pt1->y + p_pt2->y) / 2;
    p_mid->x = (p_pt1->x + p_pt2->x) / 2;
    return p_mid;
}
int main() {
    pt pt1 = {}, pt2 = {}, mid = {}, pt3 = {}, *p_mid = NULL;
    printf("请输入第一个点的位置："); 
    scanf("%d%d", &pt1.y, &pt1.x);
    printf("请输入第二个点的位置：");
    scanf("%d%d", &pt2.y, &pt2.x);
    //mid.x = (pt1.x + pt2.x) / 2;
    //mid.y = (pt1.y + pt2.y) / 2;
    //mid = midpt(pt1, pt2);
    p_mid = midpt(&pt1, &pt2, &mid);
    printf("中点位置是(%d, %d)\n", mid.y, mid.x);
    printf("中点位置是(%d, %d)\n", p_mid->y, p_mid->x);
    pt3 = mid;
    printf("中点位置是(%d, %d)\n", pt3.y, pt3.x);
    return 0;
}



