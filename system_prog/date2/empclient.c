#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#define PORTNO 4007
struct Employee {
    char name[50];
    int ID;
	float salary;
    char Gender;
};
int main()
{
	int sfd=0, retValue=0;


	struct sockaddr_in serv_address;
	struct Employee EMP;

	sfd = socket(AF_INET,SOCK_STREAM,0);

	if(sfd < 0)
	{
		perror("socket() ");
		exit(EXIT_FAILURE);
	}
	printf("\nSocket created with sockfd : %d",sfd);

	//reset/set address of client

	memset(&serv_address,'\0',sizeof(serv_address));

	// setting of Server side ipaddress and port no
	serv_address.sin_family = AF_INET;
	serv_address.sin_port = htons(PORTNO);
	serv_address.sin_addr.s_addr = INADDR_ANY;

	retValue = connect(sfd,(struct sockaddr *)&serv_address, sizeof(serv_address));
	if(retValue < 0)
	{
		perror("connect()");
		exit(EXIT_FAILURE);
	}

	printf("\nClient: Connected to the server\n");

strcpy(EMP.name, "RAM");
    EMP.ID = 14;
  	EMP.salary=5009.45;
    EMP.Gender='M';

    // Send the structure to the server
    if (send(sfd, &EMP, sizeof(EMP), 0) < 0) {
        perror("Send failed");
        exit(1);
    }

    printf("Structure sent to server.\n");

   
    close(sfd);
    return 0;
}
