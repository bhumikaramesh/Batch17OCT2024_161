#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
 
#define PORT 5566
 
void handle_client_request(int client_socket) {
    char menu[] = "\n--------------------------------------------------------\n"
                  "Call Forwarding Menu:\n"
                  "1. Enable call forwarding\n"
                  "2. Disable call forwarding\n"
                  "3. Exit\n"
                  "Enter your choice: ";
    send(client_socket, menu, strlen(menu), 0);
    char choice[10];
    recv(client_socket, choice, sizeof(choice), 0);
 
    int option = atoi(choice);
    switch (option) {
        case 1:
            printf("Call forwarding enabled!\n");
            break;
        case 2:
            printf("Call forwarding disabled!\n");
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
    }
}
 
int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
 
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
 
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
 
    // Bind the socket to the specified port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
 
    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
 
    printf("Server listening on port %d...\n", PORT);
 
    while (1) {
        // Accept a new connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
 
        printf("Client connected\n");
 
        // Handle client's request
        handle_client_request(new_socket);
 
        close(new_socket); // Close the connection with the client
    }
 
    return 0;
}
