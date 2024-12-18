#include <stdio.h> 
#include <stdlib.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
 
#define PORT 9090
 
#define MAX_CLIENTS 5
 
struct User {
    long source;
    long desti;
    char name[15];
    char call_s_type;
    char service_s;
    int pin;
};
 
void displayNewUser(struct User newUser) {
    printf("\nNew user added successfully:\n");
    printf("Source Number: %ld\n", newUser.source);
    printf("Destination Number: %ld\n", newUser.desti);
    printf("Name: %s\n", newUser.name);
    printf("Call Forwarding Type: %c\n", newUser.call_s_type);
    printf("Service Status: %c\n", newUser.service_s);
    printf("PIN: %d\n", newUser.pin);
}
 
void file_existence() {
    FILE *ffg;
    if ((ffg=fopen("user.txt", "r+")) == NULL) {
        if ((ffg=fopen("user.txt", "w+")) == NULL) {
            printf("Could not open file\n");
            exit(1);
        }
    }
    fclose(ffg);
}
 
int main() {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
 
    int addrlen = sizeof(address);
    struct User newUser;
 
    // Creating socket file descriptor
    int opt=1;
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
 
    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
 
    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    while (1) {
        printf("\nWaiting for new client registration...\n");
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        valread = read(new_socket, &newUser, sizeof(struct User));
        if (valread == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }
        displayNewUser(newUser);
        file_existence();
        FILE *file_ptr = fopen("user.txt", "a");
        fprintf(file_ptr, "%ld|%ld|%s|%c|%c|%d\n", newUser.source, newUser.desti, newUser.name, newUser.call_s_type, newUser.service_s, newUser.pin);
        fclose(file_ptr);
        close(new_socket);
    }
    return 0;
}
