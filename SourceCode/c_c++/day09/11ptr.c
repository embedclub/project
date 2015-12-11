/*
    无类型指针形式参数演示
*/
#include <stdio.h>
void print(void *p_void, int type) {
    if (type == 1) {
        printf("%d\n", *(int *)p_void);
    }
    else if (type == 2) {
        printf("%c\n", *(char*)p_void);
    }
    else if (type == 3) {
        printf("%g\n", *(float*)p_void);
    }
}
int main() {
    int num = 10;
    char ch = 'b';
    float fnum = 5.7f;
    print(&num, 1);
    print(&ch, 2);
    print(&fnum, 3);
    return 0;
}
