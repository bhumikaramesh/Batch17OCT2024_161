  #include<stdio.h>
   #include<stdlib.h>
   #include<sys/types.h>
   #include<unistd.h>
  
   int main()
   {
 /*      long int i;
     int pid=getpid();
      pid_t ppid=getppid();
      printf("\nMY own Pid=%d\n",pid);
  
  printf("\nfor %d parent is %d\n",pid,ppid);*/
  
  printf("\n I am parent and my id is %d\n",getpid());
 printf("\nParent's PPID:%d",getppid());
 pid_t id=fork();

 if(id==0)
 {
      printf("\nI am child process");
	  printf("\nMY ID=%d",getpid());
}
else
{
	printf("\nIn the parent child process id =%d",id);
}
	  printf("\nHello world\n");
	  printf("\n\n");
     return 0;
 }


