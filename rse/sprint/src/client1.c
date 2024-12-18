/***************************************************************************
*   DATE:08/12/2024
*   OWNER : Group-05
*   FILENAME : client.c
*   DESCRIPTION: Contains code for a client that connects to a server 
*               to perform various file operations, including searching for 
*               a file, searching for a word or or phrase orstring within files, 
*				and displaying file contents. The client communicates with the 
*				server via socket programming and presents options to the user
*				through a console interface.
*****************************************************************************/
#include <common.h>
#include<functions.h>

int main()
{
	int cfd = 0, retValue=0;
	int choice;
	char ans[10]={0,};
	struct sockaddr_in serv_address;

	char buffer[MAXBUFF] = {0,};

	cfd = socket(AF_INET,SOCK_STREAM,0);

	if(cfd < 0)
	{
		perror("socket() ");
		exit(EXIT_FAILURE);
	}
	printf("\nSocket created with sockfd : %d",cfd);

	//reset/set address of client 

	memset(&serv_address,'\0',sizeof(serv_address));

	// setting of Server side ipaddress and port no
	serv_address.sin_family = AF_INET;
	serv_address.sin_port = htons(PORTNO);
	serv_address.sin_addr.s_addr = INADDR_ANY;

	retValue = connect(cfd,(struct sockaddr *)&serv_address, sizeof(serv_address));

	if(retValue < 0)
	{
		perror("connect()");
		exit(EXIT_FAILURE);
	}

	printf("\nClient: Connected to the server\n");


	// strcpy(msg,"\nHi This is from Client\n");
	while(1){
        printf("\n***********************************************************\n");
        printf("\n                   REMOTE SEARCH ENGINE                    \n");
        printf("\n***********************************************************\n");
        printf("Choose an Option:\n");
        printf("\n\n");
		printf("1. List all files\n");
        printf("2. Search for a file\n");
        printf("3. Search for a string in the filesystem\n");
        printf("4. Enter the absolute path and Display the content\n");
        printf("5. Exit\n");
        printf("************************************************************\n");
        printf("\n");
        printf("Enter your choice:\n ");
        
        // Input validation for choice
        while (1) {
            if (scanf("%d", &choice) != 1) 
			{
                printf("Invalid input. Please enter a number: ");
                while (getchar() != '\n'); // Clear the input buffer
            } 
			else if (choice < 1 || choice > 5) 
                printf("Please enter a valid option (1-4): ");
			else 
                break; // Valid input, break out of the loop
            
        }

        send(cfd, &choice, sizeof(choice), 0);
		switch(choice)
		{
		case LIST_FILES: 

				recv(cfd, buffer, sizeof(buffer), 0);
                printf("Server response:\n%s\n", buffer);
				break;

		case SEARCH_FILE:

				printf("Enter the filename to search\n");
                getchar(); // clear the buffer
                scanf("%[^\n]s", buffer);
                send(cfd, buffer, sizeof(buffer), 0);
                recv(cfd, buffer, sizeof(buffer), 0);
				printf("\n %s",buffer);
				break;

		case SEARCH_STRING:

				printf("Enter the word/sentence/pattern: ");
                getchar(); // clear the buffer
                scanf("%[^\n]s", buffer);
                send(cfd, buffer, sizeof(buffer), 0);
                recv(cfd, buffer, sizeof(buffer), 0);
                printf("Files that are having the pattern :\n%s", buffer);
                if (strcmp(buffer, "") == 0) 
                    printf("This string was not found in any file\n\n");
                else
				{
				
                    printf("String found in \n %s",buffer);
                    printf("\n\n Do you want to open file [Yes/No]");
                    scanf("%s",ans);
                    if(strcmp(ans,"Yes")==0)
                        {
                            choice=4;
                            send(cfd,&choice , sizeof(choice), 0);
                            printf("\n Enter the file name: ");
                            getchar();
                            scanf("%[^\n]s",buffer);
                            printf("\n Filename is  %s",buffer);
                            send(cfd,buffer,sizeof(buffer),0);
                            recv(cfd,buffer,sizeof(buffer),0);
                            printf("\n File content : \n %s",buffer);
                            if (strcmp(buffer, "") == 0)
                            printf("There is no content in file\n\n");
                            break;
                        }


				}
				break;

		case DISPLAY_CONTENT: 

				printf("\n Enter the file name: ");
				getchar();
				scanf("%[^\n]s",buffer);
				printf("\n Filename is  %s",buffer);
				send(cfd,buffer,sizeof(buffer),0);
				recv(cfd,buffer,sizeof(buffer),0);
				printf("\n File content : \n %s",buffer);
                if (strcmp(buffer, "") == 0) 
                    printf("There is no content in file\n\n");
                break;

		case EXIT_PROGRAM:
				close(cfd);
				exit(EXIT_FAILURE);
				break;
                
		default:
				  printf("\n Invalid choice \n");
				  break;
		}
	}
	
	// close(sfd);

	return 0;
}
