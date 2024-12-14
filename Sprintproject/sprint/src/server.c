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
            case 1:  // List all  files
				printf("\n choice is 1");
                memset(result, 0, sizeof(result));  // Clear result before use
             strcpy( result,get_ls_output());

                send(csfd, result, sizeof(result), 0);
                break;
			case 2:
				printf("\n Choice is 2");
                memset(result, 0, sizeof(result));  // Clear result before use
                recv(csfd, buffer, sizeof(buffer), 0);
                strcpy(result,searchForFile(buffer));
                send(csfd, result, sizeof(result), 0);

			case 3: // serach for a pattern
				printf("\n choice is 2");
				 memset(buffer, 0, sizeof(buffer));  // Clear buffer before receiving data
                recv(csfd, buffer, sizeof(buffer), 0);
                
                strcpy(result,searchForString(buffer));
                
                send(csfd, result, sizeof(result), 0);
                memset(result, 0, sizeof(result));  // Clear result before use
                break;
			case 4: //Print the content of file
				printf("\n Choice is 4");
				memset(buffer,0,sizeof(buffer));
				recv(csfd,buffer,sizeof(buffer),0);
				
				printf("\n %s",buffer);
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
char* list_files(char *result) {
    // Create a pipe
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("Pipe failed");
        return NULL;
    }

    // Fork the process
    pid_t pid = fork();
    if (pid > 0) {
        // Parent process
        close(pipefd[1]);  // Close the write end of the pipe
		static char buffer[MAXBUFF];
        // Read the output of the ls command from the pipe
        ssize_t bytesRead = read(pipefd[0], buffer, sizeof(buffer) - 1);
        if (bytesRead > 0) {
            buffer[bytesRead] = '\0';  // Null-terminate the string
        }
        close(pipefd[0]);
        wait(NULL);  // Wait for the child process to finish
		memcpy(result,buffer,bytesRead);
        return buffer;  // Return the captured output
    } else if (pid == 0) {
        // Child process
        close(pipefd[0]);  // Close the unused read end of the pipe

        // Redirect stdout to the write end of the pipe
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);

        // Execute the ls command
        execl("/bin/ls", "ls", (char *)NULL);
        perror("execl failed"); // If execl fails
		exit(EXIT_FAILURE);
    } else {
        perror("fork failed");
        return NULL;
    }
}
char* searchString(const char* pattern) {
    static char buffer[MAXBUFF]; // Static buffer to persist after function returns

    // Create a pipe to capture the output of grep
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("Pipe failed");
        return NULL;
    }

    // Fork the process
    pid_t pid = fork();
    if (pid > 0) {
        // Parent process
        close(pipefd[1]);  // Close the write end of the pipe

        // Read the output of the grep command from the pipe
        ssize_t bytesRead = read(pipefd[0], buffer, sizeof(buffer) - 1);
        buffer[bytesRead] = '\0';  // Null-terminate the string
        close(pipefd[0]);

        wait(NULL);  // Wait for the child process to finish

        // Return the output captured from the pipe
        return buffer;
    } else if (pid == 0) {
        // Child process
        close(pipefd[0]);  // Close the unused read end of the pipe

        // Redirect the output to the pipe
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);

        // Execute the grep command
   //  execlp("/bin/grep","grep","-c", "grep -l '"pattern"' *", (char *)NULL);  // Search pattern in all files
   		char command[MAXBUFF];
		snprintf(command, sizeof(command), "grep -l '%s' *", pattern);
		execlp("sh", "sh", "-c", command, (char *)NULL);
        perror("execlp failed");  // If execl fails
//        snprintf(buffer,sizeof(buffer),"grep -rl '%s' .",pattern);
		return buffer;
	exit(EXIT_FAILURE);
    } else {
        perror("fork failed");
        return NULL;
    }
}


char *displayFileContent(char *filename)
{
	   FILE *file;
       static char buf[1024];
       int ch;
	   int i=0;
	   
	 memset(buf, 0, sizeof(buf));  
	printf("\n %s",filename);
     file = fopen(filename, "r");
     if (file == NULL) {
         perror("Error opening file");
         return "Error opening file";
     } 


     while ((ch = fgetc(file)) != EOF) {
         if (i < sizeof(buf) - 1) {
             buf[i++] = ch;
         }
     }
     buf[i] = '\0';
     fclose(file);
     return buf;
 }



