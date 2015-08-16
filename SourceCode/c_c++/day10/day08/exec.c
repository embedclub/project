#include "public.h"

int main()
{
	printf("开始运行...\n");
#if 0
	/*
		参数一， 要执行文件的路径 +名称
		参数二， 通常为执行文件的名称 
		后续参数， 该执行文件需要的具体参数
				  最后一个参数必须为NULL
	*/
	execl("/bin/ls", "ls", "-l", "/home/tarena",
			NULL);
	/*	
		参数一， 要执行文件的名称，不用加路径
                 会自动从PATH指定的路径中寻找
                 要执行的程序
		后续参数与execl相同
    */
	execlp("ls", "ls", "-l", "/home/tarena/1407",
            NULL);
#endif
	/*最后一个参数必须为NULL*/
	char *args[] = {"ls", "-l", "./", "--color=auto", NULL};	
	execvp("ls", args);
	//execv("/bin/ls", agrs);	
	printf("运行结束!\n");
	return 0;
}






