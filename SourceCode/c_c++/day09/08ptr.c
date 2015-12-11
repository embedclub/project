/*
    指针演示
*/
#include <stdio.h>
void func(int *p_num) {
    printf("请输入一个数字：");
    scanf("%d", p_num);
}
int main() {
    int num = 0;
    func(&num);
    printf("num是%d\n", num);
    return 0;
}
