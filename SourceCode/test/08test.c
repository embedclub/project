/*************************************************************************
    > File Name: 08test.c
    > Author: scc_embedclub
    > Mail: scc_ddcx@163.com 
    > Created Time: 2016年03月13日 星期日 20时58分49秒
    > Version: 1.0  
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

 
//人为规定字符串的存储位置。 
int main(int argc, char* argv[]) {   
    char   *s=NULL; 
    s=(char*)malloc(sizeof(char)*6);//让s到堆上去 
    strcpy(s, "hello ");
    s[0]='x';//ok

    char arry[] = "0123456";
    arry[1] = 'H';

    printf("the string is %s\n", s);
    printf("the arry is %s\n", arry);
          
    return 0;   
  }   
