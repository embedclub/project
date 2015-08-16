#include "public.h"
#include <dirent.h>

void print(char *path, int level)
{
	//printf("path = %s\n", path);
	DIR *dir = opendir(path);
	if(dir == NULL)
	{	
		perror("opendir failed");
		return ;
	}
	struct dirent *ent = readdir(dir);
	while(ent != NULL)
	{
		/*如果为目录*/
		if(ent->d_type == 4)
		{
			/*跳过 ./ ../*/
			if(!strcmp(ent->d_name, ".") ||
				!strcmp(ent->d_name, ".."))
			{
				ent = readdir(dir);
				continue;
			}
			printf("%*s%s\n", 4*level, "",
					ent->d_name);
			#if 1
			/*组合出子目录的完整路径*/
			char buf[1024] = {0};
			sprintf(buf, "%s%s%s",path, "/", 
					ent->d_name);
			#endif
			/*递归打印子目录*/
			print(buf, level+1);
		}
		else
		{
			printf("%*s%s\n", 4*level, "",
					ent->d_name);
		}
		ent = readdir(dir);
	}
	closedir(dir);
}

int main()
{
	print("../day02", 0);
}


