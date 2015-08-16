#include "public.h"
#include <dirent.h>

int main()
{
	DIR *dir = opendir("../day02");
	if(dir == NULL)
	{
		perror("opendir failed");
		return -1;
	}
	struct dirent *ent = readdir(dir);	
	while(ent != NULL)
	{
		printf("type=%d, name=%s\n",
				ent->d_type,
				ent->d_name);
		ent = readdir(dir);
	}





}
