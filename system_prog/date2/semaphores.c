/*
demo - semaphores
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <string.h>
#define MAX_BUFF 1024

#define PERMS 0660

int main()
{
	int semid, nsem=0;
	key_t key = ftok("/home/bhima/CapG02Feb2023/day28", 10103);

	nsem = 1;
	semid = semget(key,nsem, PERMS|IPC_CREAT);

	if(semid<0)
	{
		perror("semget()");
		_exit(EXIT_FAILURE);

	}

	printf("1 Semaphore is created with ID %d",semid);


	nsem = 30;
	semid = semget(0x20,nsem, PERMS|IPC_CREAT);

	if(semid<0)
	{
		perror("semget()");
		_exit(EXIT_FAILURE);

	}

	printf("2 Semaphore is created with ID %d",semid);


	nsem = 40;
	semid = semget(0x30,nsem, PERMS|IPC_CREAT);

	if(semid<0)
	{
		perror("semget()");
		_exit(EXIT_FAILURE);

	}

	printf("3 Semaphore is created with ID %d",semid);


	nsem = 1;
	semid = semget(0x40,nsem, PERMS|IPC_CREAT);

	if(semid<0)
	{
		perror("semget()");
		_exit(EXIT_FAILURE);

	}

	printf("4 Semaphore is created with ID %d",semid);

	printf("\n\n");
	return 0;
}
