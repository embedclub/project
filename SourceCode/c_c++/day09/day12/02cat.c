/*
    合并数组作业
*/
#include <stdio.h>
int *combine(int *p_dest, int dsize, const int *p_src, int ssize) {
    int *p_dest1 = p_dest + dsize;
    const int *p_src1 = p_src;
    while (p_src + ssize > p_src1) {
        *p_dest1 = *p_src1;
         p_src1++;
         p_dest1++;
    }
    return p_dest;
}
int main() {
    int arr1[20] = {1, 2, 3, 4};
    int arr2[] = {5, 6, 7};
    int num = 0;
    int *p_num = combine(arr1, 4, arr2, 3);
    for (num = 0;num <= 6;num++) {
        printf("%d ", arr1[num]);
        printf("%d ", *(p_num + num));
    }
    printf("\n");
    return 0;
}



