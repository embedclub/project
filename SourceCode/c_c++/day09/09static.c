/*
    静态变量演示
*/
#include <stdio.h>
void func() {
    static int num = 0;
    printf("&num是%p\n", &num);
    printf("num是%d\n", num);
    num = 3;
}
void func1() {
    int num = 0;
    func();
}
int main() {
    func();
    func1();
    return 0;
}
