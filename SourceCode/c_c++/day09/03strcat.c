/*
    strcat练习
*/
#include <stdio.h>
char *mystrcat(char *p_dest, const char *p_src) {
    char *p_dest1 = p_dest;
    const char *p_src1 = p_src;//地址的赋值方式哈
    //查找前一个字符串中'\0'字符的位置
	printf("p_dest1 = %p\n", p_dest1);
	printf("p_dest = %p\n", p_dest);
    while (*p_dest1) {
        p_dest1++;
    }
    //把后一个字符串中所有有效字符拷贝到前一个
    //字符串中
    while (*p_src1) {
        *p_dest1 = *p_src1;
        p_dest1++;
        p_src1++;
    }
    *p_dest1 = 0;
    return p_dest;
}
int main() {
    char str[20] = "abcde";
    char *p_str = mystrcat(str, "xyz");
    printf("%s\n", str);
    printf("%s\n", p_str);
    return 0;
}





