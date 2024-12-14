#include<common.h>
#include<functions.h>

void* handle_server_communication(void* cfd_ptr);
void handle_client_interaction(int cfd);

void* handle_server_communication(void* cfd_ptr) {
    int cfd = *((int*)cfd_ptr); // Get client socket file descriptor from the passed pointer
    char buffer[MAXBUFF];

    while (1) {
        // Wait for messages from the server and handle communication
        recv(cfd, buffer, sizeof(buffer), 0);
        if (strcmp(buffer, "") != 0) {
            printf("Server response: %s\n", buffer);
        }
    }
    return NULL;
}

void handle_client_interaction(int cfd) {
    int choice;
    char ans[10] = {0};
    char buffer[MAXBUFF] = {0};

    while (1) {
        printf("\n*******************************************************\n");
        printf("\n                   REMOTE SEARCH ENGINE                        \n");
        printf("\n*******************************************************\n");
        printf("Choose an Option:\n");
        printf("1. List all files\n");
        printf("2. Search for a file\n");
        printf("3. Search for a string in the filesystem\n");
        printf("4. Enter the absolute path and Display the content\n");
        printf("5. Exit\n");
        printf("*********************************************************\n");
        printf("\nEnter your choice: ");

        // Input validation for choice
        while (1) {
            if (scanf("%d", &choice) != 1) {
                printf("Invalid input. Please enter a number: ");
                while (getchar() != '\n'); // Clear the input buffer
            } else if (choice < 1 || choice > 5) {
                printf("Please enter a valid option (1-5): ");
            } else {
                break; // Valid input, break out of the loop
            }
        }

        send(cfd, &choice, sizeof(choice), 0); // Send choice to the server

        switch (choice) {
        case LIST_FILES:
            recv(cfd, buffer, sizeof(buffer), 0);
            printf("Server response:\n%s\n", buffer);
            break;

        case SEARCH_FILE:
            printf("Enter the filename to search: ");
            getchar(); // clear the buffer
            scanf("%[^\n]s", buffer);
            send(cfd, buffer, sizeof(buffer), 0);
            recv(cfd, buffer, sizeof(buffer), 0);
            printf("%s\n", buffer);
            if (strcmp(buffer, "") == 0)
                printf("\nFile not found\n");
            break;

        case SEARCH_STRING:
            printf("Enter the word/sentence/pattern: ");
            getchar(); // clear the buffer
            scanf("%[^\n]s", buffer);
            send(cfd, buffer, sizeof(buffer), 0);
            recv(cfd, buffer, sizeof(buffer), 0);
            if (strcmp(buffer, "") == 0)
                printf("This string was not found in any file\n\n");
            else {
                printf("String found in \n%s\n", buffer);
                printf("\nDo you want to open the file [Yes/No]: ");
                scanf("%s", ans);
                if (strcmp(ans, "Yes") == 0) {
                    choice = 4;
                    send(cfd, &choice, sizeof(choice), 0);
                    printf("\nEnter the file name: ");
                    getchar();
                    scanf("%[^\n]s", buffer);
                    send(cfd, buffer, sizeof(buffer), 0);
                    recv(cfd, buffer, sizeof(buffer), 0);
                    printf("\nFile content:\n%s\n", buffer);
                }
            }
            break;

        case DISPLAY_CONTENT:
            printf("\nEnter the file name: ");
            getchar();
            scanf("%[^\n]s", buffer);
            send(cfd, buffer, sizeof(buffer), 0);
            recv(cfd, buffer, sizeof(buffer), 0);
            printf("\nFile content:\n%s\n", buffer);
            if (strcmp(buffer, "") == 0)
                printf("There is no content in the file\n\n");
            break;

        case EXIT_PROGRAM:
			close(cfd);
            exit(EXIT_FAILURE);
            break;

        default:
            printf("\nInvalid choice\n");
            break;
        }
    }
}
int main() {
    int cfd = 0, retValue = 0;
    struct sockaddr_in serv_address;

    // Create socket
    cfd = socket(AF_INET, SOCK_STREAM, 0);
    if (cfd < 0) {
        perror("socket()");
        exit(EXIT_FAILURE);
    }

    printf("\nSocket created with sockfd: %d", cfd);

    // Reset and set address of client
    memset(&serv_address, '\0', sizeof(serv_address));
    serv_address.sin_family = AF_INET;
    serv_address.sin_port = htons(PORTNO);
    serv_address.sin_addr.s_addr = INADDR_ANY;

    // Connect to the server
    retValue = connect(cfd, (struct sockaddr*)&serv_address, sizeof(serv_address));
    if (retValue < 0) {
        perror("connect()");
        exit(EXIT_FAILURE);
    }
    printf("\nClient: Connected to the server\n");

    // Create a thread to handle server communication
    pthread_t server_thread;
    if (pthread_create(&server_thread, NULL, handle_server_communication, &cfd) != 0) {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }

while(1)
{// Main thread handles user input and sends requests to the server
    handle_client_interaction(cfd);
	// Wait for the server communication thread to finish (though it may run indefinitely)
    pthread_join(server_thread, NULL);
}
    close(cfd);
    return 0;
}

