/*
    二级指针演示
*/
#include <stdio.h>
int main() {
    int num = 0;
    int *p_num = &num;
    int **pp_num = &p_num;  //二级指针声明
    **pp_num = 10;
    printf("num是%d,**pp_num是%d\n", num, **pp_num);
    *pp_num = NULL;
    printf("p_num是%p,*pp_num是%p\n", p_num, *pp_num);
    pp_num = NULL;
    printf("pp_num是%p\n", pp_num);
    return 0;
}




