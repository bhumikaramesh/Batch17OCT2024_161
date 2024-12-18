#include<stdio.h>
   #include<stdlib.h>
   #include<sys/types.h>
   #include<unistd.h>
  #include<sys/wait.h>

int main(int argc,char *argv[])
{
	printf("\nday2p3.c\n");
	printf("\nPID:%d",getpid());
	printf("\n%s\n%s",argv[0],argv[1]);
	printf("\nHello,%s\nWelcome to the world of programming\n",argv[1]);
	return 0;
}
