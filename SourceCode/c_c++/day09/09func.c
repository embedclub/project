/*
    函数练习
*/
#include <stdio.h>
void neg(int arr[], int size) {
    int num = 0;
    for (num = 0;num <= size - 1;num++) {
        arr[num] = 0 - arr[num];
    }
}
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7}, num = 0; 
    neg(arr, 7);
    for (num = 0;num <= 6;num++) {
        printf("%d ", arr[num]);
    }
    printf("\n");
    return 0;
}




