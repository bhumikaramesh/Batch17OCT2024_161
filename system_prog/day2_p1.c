#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	printf("\nThis is prog\n");
		if(fork()>0)
	{
		wait(0);
		printf("\nPrg04 PID:%d",getpid());
	}

	else

		execl("/bin/date","/bin/date",(char *)0);
	printf("\nending Prog\n");
	printf("\n");
	return 0;
}
