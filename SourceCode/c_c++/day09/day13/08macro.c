/*
    宏和函数区别演示
*/
#include <stdio.h>
#define   ABS(n)        n >= 0 ? n : 0 - n
#define   ABS1(res, n)  (res = (n) >= 0 ? (n) : 0 - (n))
#define   SUB(x, y)     ((x) - (y))
/*int abs(int num) {
    if (num >= 0) {
        return num;
    }
    else {
        return 0 - num;
    }
}*/
void abs1(int res, int num) {
    if (num >= 0) {
        res = num;
    }
    else {
        res = 0 - num;
    }
}
int main() {
    int num = 0, res = 0;
    printf("请输入一个整数："); 
    scanf("%d", &num);
    //printf("绝对值是%d\n", abs(num));
    abs1(res, num);
    printf("绝对值是%d\n", res);
    ABS1(res, num);
    //printf("绝对值是%d\n", ABS(num));
    printf("绝对值是%d\n", res);
    printf("SUB(20, 10)是%d\n", SUB(20, 10));
    printf("30 - SUB(20, 10)是%d\n", 30 - SUB(20, 10));
    printf("SUB(20, 15 - 5)是%d\n", SUB(20, 15 - 5));
    return 0;
}
