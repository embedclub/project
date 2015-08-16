/*
    指针作业
*/
#include <stdio.h>
int *reverse(int *p_num, int size) {
    int *p_pre = p_num, *p_post = p_num + size - 1;
    while (p_pre < p_post) {
        int tmp = *p_pre;
        *p_pre = *p_post;
        *p_post = tmp;
        p_pre++;
        p_post--;
    }
    return p_num;
}
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7}, num = 0;
    int *p_num = reverse(arr, 7);
    for (num = 0;num <= 6;num++) {
        printf("%d ", arr[num]);
        printf("%d ", *(p_num + num));
    }
    printf("\n");
    return 0;
}




