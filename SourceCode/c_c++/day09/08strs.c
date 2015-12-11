/*
    多个字符串演示
	二位数组哈
*/
#include <stdio.h>
int main() {
    /*char countries[5][20] = {"China", "Russia", 
               "England", "France", "America"};*/
    char *countries[5] = {"China", "Russia",
               "England", "France", "America"};
    char **pp_countries = countries;
    int num = 0;
    for (num = 0;num <= 4;num++) {
        printf("%s\n", countries[num]);
        printf("%s\n", *(pp_countries + num));
    }
    return 0;
}



