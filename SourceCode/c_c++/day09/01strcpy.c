/*
    字符串拷贝作业
*/
#include <stdio.h>
#include <stdlib.h>
char *mystrcpy(const char *p_src, char **pp_dest) {
    const char *p_src1 = p_src;
    //计算原始字符串中存储区的个数
    while (*p_src1) {
        p_src1++;
    }
    //为新字符串动态分配存储区
    *pp_dest = (char*)malloc(p_src1 - p_src + 1);
    if (*pp_dest) {
        //拷贝字符串
        char *p_dest = *pp_dest;
        p_src1 = p_src;
        while (*p_src1) {
            *p_dest = *p_src1;
            p_dest++;
            p_src1++;
        }
        *p_dest = 0;
    }
    return *pp_dest;
}
int main() {
    char *p_str = NULL, *p_str1 = NULL;
	const char *p_str2 = "abc123";
    printf("%s\n", p_str2);
    p_str1 = mystrcpy("abcdef", &p_str);
    if (p_str) {
        printf("%s\n", p_str);
        printf("%s\n", p_str1);
        free(p_str);
        p_str = NULL;
        p_str1 = NULL;
    }
    return 0;
}

//字符串提供的是一个静态的地址，不能修改其数据里的内容哈！



