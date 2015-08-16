/*
    指针形参演示
*/
#include <stdio.h>
void func(const int *p_num, int size) {
    int num = 0;
    for (num = 0;num <= size - 1;num++) {
        printf("%d ", *(p_num + num));
    }
    printf("\n");
}
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    func(arr, 5);
    return 0;
}
