#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>

extern **environ;

int main(int argc,char *argv[],char *envp[])
{
	int i;
	char *temp;
	for(i=0;envp[i];i++){
	printf("\n%s",environ[i]);}
	return 0;
	}
