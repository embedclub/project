/*
    fread作业
*/
#include <stdio.h>
int main() {
    int arr[5] = {}, size = 0, num = 0;
    FILE *p_file = fopen("a.bin", "rb");
    if (p_file) {
        size = fread(arr, sizeof(int), 5, p_file);
        printf("一共获得%d个整数数据\n", size);
        for (num = 0;num <= 4;num++) {
            printf("%d ", arr[num]);
        }
        printf("\n");
        fclose(p_file);
        p_file = NULL;
    }
    return 0;
}
