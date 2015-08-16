/*
    宏演示
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int lottery[SIZE] = {}, num = 0;
    srand(time(0));
    for (num = 0;num <= SIZE - 1;num++) {
        lottery[num] = rand() % 36 + 1;
    }
    for (num = 0;num <= SIZE - 1;num++) {
        printf("%d ", lottery[num]);
    }
    printf("\n");
    return 0;
}







