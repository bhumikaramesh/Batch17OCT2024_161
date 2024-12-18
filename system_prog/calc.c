#include<stdio.h>
#include<stdlib.h>
#include<sys\types.h>
#include<unistd.h>

int main(int argc,char *argv[])

{
printf("\n in the prog\n");
execl(argv[1],argv[2],argv[3],(char*)0);
printf("\nthis line will not print");
return 0;
}
	
