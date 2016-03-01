
#include <stdio.h>
#include <stdlib.h>
//(void)
//(argc, argv)
int main(int argc, char **argv, char **env)
{
	extern char **environ; //等效于env
	printf("env=%p, environ=%p\n", env, environ);
	char *value = getenv("LANG");
	printf("value = %s\n", value);//语言
	putenv("VAR=aaaa");//定义新的环境变量VAR
	putenv("LANG=abc");//修改环境变量LANG
	printf("LANG=%s\n", getenv("LANG"));
	printf("VAR=%s\n", getenv("VAR"));
	setenv("VAR", "1234", 0);//不改
	printf("VAR=%s\n", getenv("VAR"));
	setenv("VAR", "1234", 1);//改
	printf("VAR=%s\n", getenv("VAR"));
	unsetenv("VAR");//单删
	printf("VAR=%s\n", getenv("VAR"));
	clearenv();
	printf("LANG=%s\n", getenv("LANG"));
	return 0;
}



