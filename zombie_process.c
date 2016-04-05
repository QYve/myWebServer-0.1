
#include "zombie_process.h"

void sighandler(int signo)
{
	printf("catch signo = %d\n",signo);
	while(1)
	{
		int ret= waitpid(-1,NULL,WNOHANG);
		printf("ret = %d\n",ret);
		if(ret > 0) return;
	}
}