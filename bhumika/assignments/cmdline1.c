#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 40
#define MAX_IP_LENGTH 16

// Define the server structure
struct server {
    char name[MAX_NAME_LENGTH];
    char ip[MAX_IP_LENGTH]; // IPv4 address, max length of 15 (e.g., "255.255.255.255")
    unsigned short port;
};

// Function to display the server configuration
void display(const struct server *servercfg) {
    printf("\nServer Configuration:\n");
    printf("Name: %s\n", servercfg->name);
    printf("IP Address: %s\n", servercfg->ip);
    printf("Port: %u\n", servercfg->port);
}

// Function to validate the IP address
int validate_ip(const char *ip) {
    int octets[4];
    if (sscanf(ip, "%d.%d.%d.%d", &octets[0], &octets[1], &octets[2], &octets[3]) != 4) {
        return 0; // Invalid format
    }
    for (int i = 0; i < 4; i++) {
        if (octets[i] < 0 || octets[i] > 255) {
            return 0; // Invalid range
        }
    }
    return 1; // Valid IP
}

// Function to validate the port number
int validate_port(unsigned short port) {
    return (port >= 1 && port <= 65535); // Valid port range
}

// Function to read and validate inputs
int read_input(const char *prompt, char *buffer, int buffer_size) {
    printf("%s", prompt);
    if (fgets(buffer, buffer_size, stdin)) {
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove trailing newline
        return 1; // Success
    }
    return 0; // Failure
}

// Function to update the server configuration
int update(struct server *servercfg) {
    char buffer[MAX_NAME_LENGTH];
    char ip_buffer[MAX_IP_LENGTH];
    unsigned short port;

    // Update server name
    if (!read_input("Enter new server name (max 40 characters): ", buffer, MAX_NAME_LENGTH)) {
        printf("Failed to read server name.\n");
        return 0; // Failure
    }
    strncpy(servercfg->name, buffer, MAX_NAME_LENGTH);

    // Update IP Address
    if (!read_input("Enter new IP Address (e.g., 192.168.1.1): ", ip_buffer, MAX_IP_LENGTH) || !validate_ip(ip_buffer)) {
        printf("Invalid IP address format.\n");
        return 0; // Failure
    }
    strncpy(servercfg->ip, ip_buffer, MAX_IP_LENGTH);

    // Update port number
    printf("Enter new port number (1-65535): ");
    if (scanf("%hu", &port) != 1 || !validate_port(port)) {
        printf("Invalid port number.\n");
        return 0; // Failure
    }
    servercfg->port = port;

    // Consume the trailing newline character from the previous input
    getchar();

    return 1; // Success
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Error: Expected 3 arguments (name, IP address, port number).\n");
        return 1; // Failure
    }

    // Allocate memory for the server structure
    struct server servercfg;

    // Validate and read arguments
    // Server name
    strncpy(servercfg.name, argv[1], MAX_NAME_LENGTH - 1);
    servercfg.name[MAX_NAME_LENGTH - 1] = '\0'; // Ensure null-termination

    // Validate IP address
    if (!validate_ip(argv[2])) {
        printf("Invalid IP address format.\n");
        return 1; // Failure
    }
    strncpy(servercfg.ip, argv[2], MAX_IP_LENGTH - 1);
    servercfg.ip[MAX_IP_LENGTH - 1] = '\0'; // Ensure null-termination

    // Validate port number
    unsigned short port = (unsigned short)atoi(argv[3]);
    if (!validate_port(port)) {
        printf("Invalid port number.\n");
        return 1; // Failure
    }
    servercfg.port = port;

    // Display the initial configuration
    display(&servercfg);

    // Ask the user if they want to update the configuration
    char choice;
    printf("\nDo you want to update the server configuration? (y/n): ");
    getchar(); // Consume the leftover newline character from previous input
    scanf("%c", &choice);

    if (choice == 'y' || choice == 'Y') {
        // Update the configuration
        if (update(&servercfg)) {
            printf("Updated configuration:\n");
            display(&servercfg);
        } else {
            printf("Failed to update the configuration.\n");
        }
    }

    return 0;
}

