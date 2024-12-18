#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

struct Employee {
    char name[50];
    int ID;
	float salary;
    char Gender;
  
};

int main() {
    int sfd, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len;
    struct Employee EMP;

    sfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(65432);  // Port number
    server_addr.sin_addr.s_addr = INADDR_ANY;  // Bind to any available address

    if (bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(1);
    }

    if (listen(server_sock, 1) < 0) {
        perror("Listen failed");
        exit(1);
    }

    printf("Server is waiting for a connection...\n");

    client_len = sizeof(client_addr);
    client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &client_len);
    if (client_sock < 0) {
        perror("Accept failed");
        exit(1);
    }

    if (recv(client_sock, &EMP, sizeof(EMP), 0) < 0) {
        perror("Receive failed");
        exit(1);
    }

    printf("Received structure:\n");
    printf("Name: %s\n", EMP.name);
    printf("Age: %d\n", EMP.ID);
    printf("salary: %f\n", EMP.salary);
    printf("Gender: %c\n", EMP.Gender);


    close(client_sock);
    close(server_sock);

    return 0;
}

