/*********************************************************************************&********
 *   DATE: 13/12/2024
 *   OWNER : Group-05
 *   FILENAME : server1.c
 *   DESCRIPTION:  This file contains the server-side code for a multi-threaded server 
 *                 that supports concurrent client connections. The server provides
 *                  functionalities  like searching for files, searching for strings
 *				   within files, and displaying file contents.  It manages multiple
 *				   client requests using threads and ensures thread safety with mutex locks.
 *				   Log file is maintained to monitor at 4 levels(INFO,DEBUG,FATAL,WARN)
 *******************************************************************************************/
#include<common.h>
#include<functions.h>

pthread_mutex_t client_count_lock;
int active_clients = 0;

void* handleClient(void* csfdp);
int main()
{
	log_message("INFO","Creating Socket");
	int sfd = 0, retValue=0, csfd;
	//int clientAddlen = 0;
	struct sockaddr_in serv_address;

	
	sfd = socket(AF_INET,SOCK_STREAM,0);

	if(sfd < 0)
	{
		log_message("FATAL","Socket creation failed");
		perror("socket() ");
		exit(EXIT_FAILURE);
	}
	printf("\nSocket created with sockfd : %d\n",sfd);
	log_message("INFO","Socket created");
	//reset/set address of server 
	log_message("INFO","Building Port");
	memset(&serv_address,'\0',sizeof(serv_address));

	serv_address.sin_family = AF_INET;
	serv_address.sin_port = htons(PORTNO);
	serv_address.sin_addr.s_addr = INADDR_ANY;//inet_addr("127.0.0.1");

	retValue = bind(sfd, (struct sockaddr *)&serv_address,sizeof(serv_address));
	if(retValue < 0)
	{
		log_message("FATAL","Bind failed");
		perror("bind()");
		exit(EXIT_FAILURE);
	}

	printf("\nBinded the server to the ipaddress with portno\n");
	log_message("INFO","Listening to clients");
	retValue = listen(sfd,MAX_CLIENTS);
	if(retValue < 0)
	{
		log_message("FATAL","Listen Failed");
		perror("listen() ");
		exit(EXIT_FAILURE);
	}
	printf("\nListening to the clients now\n");
 	pthread_mutex_init(&client_count_lock, NULL);

    while (1) {
        pthread_mutex_lock(&client_count_lock);
        if (active_clients >= MAX_CLIENTS) {    
            pthread_mutex_unlock(&client_count_lock);
			log_message("WARN","Max clients reached,in waiting state");
            sleep(1);
            continue;
        }
        pthread_mutex_unlock(&client_count_lock);

        //csfd = (int *)malloc(sizeof(int));
/*        if(csfd== NULL)
		{
			log_message("FATAL","Memory Allocation Failed");
			continue;
		}
*/

        csfd= accept(sfd, NULL, NULL);
		printf("\n Client connected");
        if (csfd== -1) {
			log_message("FATAL","Accept Failed");
            //free(csfd);
            continue;
        }

        
		log_message("INFO","Client connected");
        pthread_mutex_lock(&client_count_lock);
        active_clients++;
        pthread_mutex_unlock(&client_count_lock);

        pthread_t clientThread;
        if (pthread_create(&clientThread, NULL, handleClient,(void *)&csfd) != 0) {
           close(csfd);
           	//free(csfd);
			log_message("FATAL","Failed to create thread");
            pthread_mutex_lock(&client_count_lock);
            active_clients--;
            pthread_mutex_unlock(&client_count_lock);
        } else {
            pthread_detach(clientThread);
        }
    
}
    log_message("INFO","Closing server socket");
    close(sfd);
//	free(csfd);
    pthread_mutex_destroy(&client_count_lock);
    return 0;
}

void* handleClient(void* csfdp)
{ 
	int csfd= *(int *)csfdp;
	int choice;
	char result[MAXBUFF]= {0,};
	static char buffer[MAXBUFF]={0,};

			while(1)
			{
			  recv(csfd, &choice, sizeof(choice), 0);
			 switch (choice) {
            case LIST_FILES:// List all  files
				log_message("DEBUG","Received request to list files");
				printf("\n choice is 1");
                memset(result, 0, sizeof(result));  // Clear result before use
          		strncpy( result,get_ls_output(),sizeof(result));
                send(csfd, result, sizeof(result), 0);
                memset(result, 0, sizeof(result));  // Clear result before use
				log_message("DEBUG", "Sent file list to client.");
                break;
			case SEARCH_FILE:
				printf("\n Choice is 2");
				log_message("DEBUG", "Received request to search for a file.");
				memset(buffer, 0, sizeof(buffer));  // Clear buffer before receiving data
                recv(csfd, buffer, sizeof(buffer), 0);
                char *result1=searchForFile(buffer);
				if(result1==NULL)
					strcpy(result,"Not found");
				else{
					strcpy(result,result1);
					free(result1);}
                send(csfd, result, sizeof(result), 0);
				log_message("DEBUG", "Sent search result to client.");
				break;
			case SEARCH_STRING: // serach for a pattern
				printf("\n choice is 3");
				log_message("DEBUG", "Received request to search for a pattern.");
				memset(buffer, 0, sizeof(buffer));  // Clear buffer before receiving data
                recv(csfd, buffer, sizeof(buffer), 0);
                strncpy(result,searchForString(buffer),sizeof(result));
                send(csfd, result, sizeof(result), 0);
                memset(result, 0, sizeof(result));  // Clear result before use
				log_message("DEBUG", "Sent pattern search result to client.");
                break;
			case DISPLAY_CONTENT: //Print the content of file
				printf("\n Choice is 4");
				log_message("DEBUG", "Received request to display file content.");
				memset(buffer,0,sizeof(buffer));
				recv(csfd,buffer,sizeof(buffer),0);
				printf("\n %s",buffer);
				memset(result,0,sizeof(result));
				strncpy(result,displayFileContents(buffer),sizeof(result));
				send(csfd,result,sizeof(result),0);
                memset(result, 0, sizeof(result));  // Clear result before use
				log_message("DEBUG", "Sent file content to client.");
				break;
			  case EXIT_PROGRAM:  // Client exit
                log_message("INFO","Client disconnected");
                close(csfd);
			//	free(csfdp);
                pthread_mutex_lock(&client_count_lock);
                active_clients--;
                pthread_mutex_unlock(&client_count_lock);
                pthread_exit(NULL);
			}
	
}
                log_message("INFO","Client disconnected");
				close(csfd);
			//	free(csfdp);
                pthread_mutex_lock(&client_count_lock);
                active_clients--;
                pthread_mutex_unlock(&client_count_lock);
                pthread_exit(NULL);
	
}

