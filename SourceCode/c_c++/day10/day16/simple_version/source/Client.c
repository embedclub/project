
#include "../include/Client.h"

int main()
{
	signal(SIGINT, sigFunc);

	Client_Create();

	Pthread_Create();
	
	while(1);

	return 0;
}
