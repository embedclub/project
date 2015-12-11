/*
    彩票作业
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int lottery[7];
void create() {
    int num = 0;
    for (num = 0;num <= 6;num++) {
        lottery[num] = rand() % 36 + 1;
    }
}
int main() {
    int num = 0;
    srand(time(0));
    create();
    for (num = 0;num <= 6;num++) {
        printf("%d ", lottery[num]);
    }
    printf("\n");
    return 0;
}



