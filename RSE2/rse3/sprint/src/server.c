#include<common.h>
#include<functions.h>

/*  char* displayFileContent(char *);
  char* list_files(char *);
  char* searchString(const char* );*/
int main()
{
	int sfd = 0, retValue=0, csfd=0;
	int clientAddlen = 0;
	int choice;
	struct sockaddr_in serv_address, client_address;

	char result[MAXBUFF]= {0,};
static	char buffer[MAXBUFF]={0,};
	sfd = socket(AF_INET,SOCK_STREAM,0);

	if(sfd < 0)
	{
		perror("socket() ");
		exit(EXIT_FAILURE);
	}
	printf("\nSocket created with sockfd : %d\n",sfd);

	//reset/set address of server 

	memset(&serv_address,'\0',sizeof(serv_address));

	serv_address.sin_family = AF_INET;
	serv_address.sin_port = htons(PORTNO);
	serv_address.sin_addr.s_addr = INADDR_ANY;//inet_addr("127.0.0.1");

	retValue = bind(sfd, (struct sockaddr *)&serv_address,sizeof(serv_address));
	if(retValue < 0)
	{
		perror("bind()");
		exit(EXIT_FAILURE);
	}

	printf("\nBinded the server to the ipaddress with portno\n");
	
	retValue = listen(sfd, 5);
	if(retValue < 0)
	{
		perror("listen() ");
		exit(EXIT_FAILURE);
	}
	printf("\nListening to the clients now\n");

	while(1){
		csfd = accept(sfd,(struct sockaddr *)&client_address,&clientAddlen);
		printf("\n Client connected");
		if(fork()==0){
			while(1)
			{
			  recv(csfd, &choice, sizeof(choice), 0);
		 switch (choice) {
            case LIST_FILES:  // List all  files
				printf("\n choice is 1");
                memset(result, 0, sizeof(result));  // Clear result before use
             strcpy( result,get_ls_output());

                send(csfd, result, sizeof(result), 0);
                break;
			case SEARCH_FILE:
				printf("\n Choice is 2");
                memset(result, 0, sizeof(result));  // Clear result before use
                recv(csfd, buffer, sizeof(buffer), 0);
                strcpy(result,searchForFile(buffer));
                send(csfd, result, sizeof(result), 0);

			case SEARCH_STRING: // serach for a pattern
				printf("\n choice is 3");
				 memset(buffer, 0, sizeof(buffer));  // Clear buffer before receiving data
                recv(csfd, buffer, sizeof(buffer), 0);
                
                strcpy(result,searchForString(buffer));
                
                send(csfd, result, sizeof(result), 0);
                memset(result, 0, sizeof(result));  // Clear result before use
                break;
			case DISPLAY_CONTENT: //Print the content of file
				printf("\n Choice is 4");
				memset(buffer,0,sizeof(buffer));
				recv(csfd,buffer,sizeof(buffer),0);
				
				memset(result,0,sizeof(result));
				strcpy(result,displayFileContents(buffer));
				
				send(csfd,result,sizeof(result),0);
				break;
			}
		}//end of fork
	}


	
	close(sfd);
	
	return 0;
}
}
