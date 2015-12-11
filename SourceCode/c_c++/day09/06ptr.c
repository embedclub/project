/*
    指针数组演示
	对于数组名使用sizeof得到的是整个数组的所有元素占据的字节数
*/
#include <stdio.h>
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int *p_num = arr;
    printf("sizeof(arr)是%d,sizeof(p_num)是%d\n", sizeof(arr), sizeof(p_num));
    printf("arr是%p,&arr是%p\n", arr, &arr);
    printf("p_num是%p,&p_num是%p\n", p_num, &p_num);
    return 0;
}
