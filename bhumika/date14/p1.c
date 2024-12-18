#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#include<unistd.h>
#define ITNERS=1000;

void printHello();
int main()
{
	pthread_t tid;
	int status =0;
	printf("\n in the main function");
	printf("\nI am main program ");

	status=pthread_create(&tid,NULL,printHello,NULL);

	pthread_join(tid,NULL);

	printf("\n after completing main");

	sleep(5);
	return 0;
}

void printHello()
{int i;
printf("\n hello world\n");
for(i=0;i<ITNERS;i++)
printf("\n\ti=%d",i)
}
