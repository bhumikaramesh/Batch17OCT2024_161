#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	long int i;
	int pid=getpid();
	pid_t ppid=getppid();
	printf("\nMY own Pid=%d\n",pid);
	printf("\nfor %d parent is %d\n",pid,ppid);
	getchar();
	printf("\n\n");
	return 0;
}
