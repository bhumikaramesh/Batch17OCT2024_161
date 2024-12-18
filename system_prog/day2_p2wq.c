#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>


int main()
{
	printf("\nthis is prog\n");

	if(execl("/bin/ls","ls",(char *)0<0))
	{
	perror("execl:");
	exit(EXIT_FAILURE);
	}
	printf("\n");
	return 0;
}
