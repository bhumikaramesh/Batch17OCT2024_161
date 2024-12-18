#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc,char *argv[])
{
printf("\nIn the system.c\n");
execl(argv[1],argv[2],(char*)0);
printf("\n this line will not print");

return 0;


}

