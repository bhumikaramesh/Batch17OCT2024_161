#include<stdio.h>
  #include<stdlib.h>
   #include<sys/types.h>
   #include<unistd.h>

   int main()
   {
   	pid_t id = fork();
	printf("\nI am in parent and my id is:%d\n",getpid());
	printf("\nparent's PPID :%d\n",getppid());

	if(id==0)
	{
	fork();
	printf("\nI am in child process\n");
	printf("\nMy id is %d",getpid());

}
else
{
fork();
printf("\nin the parent child process id=%d",id);
printf("\nMy id =%d",getpid());
}
printf("\n\n");
return 0;
}



