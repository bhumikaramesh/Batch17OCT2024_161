#include<stdio.h>
  #include<stdlib.h>
   #include<sys/types.h>
   #include<unistd.h>

   int main()
   {
static int a=10;
   int pid;
   pid=fork();
   if(pid<0)
   {
   	printf("\n unable to fork()");
	exit(EXIT_FAILURE);
	}
	else if(pid==0)
	{
	a+=20;
	printf("\nChild a=%d\n",a);
	}

	else 
	{
		a*=2;
		printf("\nparent a=%d\n",a);
		}
		printf("\nA=%d\n",a);
		return 0;
		}
