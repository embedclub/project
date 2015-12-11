/*
    函数练习
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void create(int arr[], int size) {
    int num = 0;
    for (num = 0;num <= size - 1;num++) {
        arr[num] = rand() % 36 + 1;
    }
}
int main() {
    int arr[2000000] = {}, num = 0;
    srand(time(0));
    create(arr, 2000000);
    for (num = 0;num <= 2000000 - 1;num++) {
        printf("%d ", arr[num]);
    }
    printf("\n");
    return 0;
}



