/*
    结构体练习
*/
#include <stdio.h>
typedef struct {
    int x, y;
} pt;
typedef struct {
    pt pt1, pt2;
} rect;
int main() {
    pt pt1 = {1, 2};
    //rect r1 = {{3, 6}, {10, 15}};
    rect r1 = {3, 6, 10, 15};
    //rect r1 = {3, 6};
    printf("(%d,%d)\n", pt1.x, pt1.y);
    printf("((%d, %d), (%d, %d))\n", r1.pt1.x, r1.pt1.y, r1.pt2.x, r1.pt2.y);
    return 0;
}





