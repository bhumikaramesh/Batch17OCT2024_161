#include<common.h>
#include<functions.h>

void* handle_client(void* arg) {
    int csfd = *((int*)arg);  // Get the client socket descriptor
    free(arg);  // Free the passed pointer

    int choice;
    char result[MAXBUFF] = {0};
    char buffer[MAXBUFF] = {0};

    // Handle the client requests
    while (1) {
        recv(csfd, &choice, sizeof(choice), 0);  // Receive the client's choice
        switch (choice) {
            case 1:  // LIST_FILES: List all files
                printf("\nChoice is 1 (List Files)\n");
                memset(result, 0, sizeof(result));  // Clear result before use
                strcpy(result, get_ls_output());
                send(csfd, result, sizeof(result), 0);
                break;

            case 2:  // SEARCH_FILE: Search for a file
                printf("\nChoice is 2 (Search File)\n");
                memset(result, 0, sizeof(result));  // Clear result before use
                recv(csfd, buffer, sizeof(buffer), 0);  // Receive the filename
                strcpy(result, searchForFile(buffer));
                send(csfd, result, sizeof(result), 0);
                break;

            case 3:  // SEARCH_STRING: Search for a pattern
                printf("\nChoice is 3 (Search String)\n");
                memset(buffer, 0, sizeof(buffer));  // Clear buffer before receiving data
                recv(csfd, buffer, sizeof(buffer), 0);
                strcpy(result, searchForString(buffer));
                send(csfd, result, sizeof(result), 0);
                break;

            case 4:  // DISPLAY_CONTENT: Print the content of a file
                printf("\nChoice is 4 (Display Content)\n");
                memset(buffer, 0, sizeof(buffer));  // Clear buffer before receiving filename
                recv(csfd, buffer, sizeof(buffer), 0);  // Receive the filename
                printf("\nReceived filename: %s\n", buffer);
                memset(result, 0, sizeof(result));  // Clear result before use
                strcpy(result, displayFileContents(buffer));
                send(csfd, result, sizeof(result), 0);
                break;

            default:
                printf("\nInvalid choice received\n");
                break;
        }
    }

    close(csfd);  // Close the client socket when done
    return NULL;  // Return from the thread
}

int main() {
    int sfd = 0, retValue = 0, *csfd = NULL;
    socklen_t clientAddlen = 0;
    struct sockaddr_in serv_address, client_address;
    pthread_t thread_id;  // Thread identifier

    sfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sfd < 0) {
        perror("socket()");
        exit(EXIT_FAILURE);
    }
    printf("\nSocket created with sockfd: %d\n", sfd);

    // Set the server address
    memset(&serv_address, 0, sizeof(serv_address));
    serv_address.sin_family = AF_INET;
    serv_address.sin_port = htons(PORTNO);
    serv_address.sin_addr.s_addr = INADDR_ANY;

    retValue = bind(sfd, (struct sockaddr*)&serv_address, sizeof(serv_address));
    if (retValue < 0) {
        perror("bind()");
        exit(EXIT_FAILURE);
    }
    printf("\nBound the server to the IP address with port number\n");

    retValue = listen(sfd, 5);
    if (retValue < 0) {
        perror("listen()");
        exit(EXIT_FAILURE);
    }
    printf("\nListening for clients now\n");

    while (1) {
        // Accept client connection
        csfd = malloc(sizeof(int));  // Dynamically allocate memory for client socket
        *csfd = accept(sfd, (struct sockaddr*)&client_address, &clientAddlen);
        if (*csfd < 0) {
            perror("accept()");
            free(csfd);  // Free allocated memory for csfd if accept fails
            continue;    // Continue to the next client
        }
        printf("\nClient connected\n");

        // Create a new thread to handle the client
        if (pthread_create(&thread_id, NULL, handle_client, csfd) != 0) {
            perror("pthread_create()");
            free(csfd);  // Free csfd if thread creation fails
            continue;
        }

        // Detach the thread so it will clean up automatically when finished
//        pthread_detach(thread_id);
    }

    close(sfd);  // Close the server socket when done
    return 0;
}

