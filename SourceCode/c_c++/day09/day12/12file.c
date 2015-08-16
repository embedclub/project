/*
    fwrite演示
*/
#include <stdio.h>
int main() {
    int arr[] = {1, 2, 3, 4, 5}, size = 0;
    FILE *p_file = fopen("a.bin", "wb");
    if (p_file) {
        size = fwrite(arr, sizeof(int), 5, p_file);
        printf("成功写入%d个整数\n", size);
        fclose(p_file);
        p_file = NULL;
    }
    return 0;
}
