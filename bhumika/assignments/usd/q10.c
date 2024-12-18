#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    E2F = 1, 
    E2,      
    E3,       
    E4,       
    E5       
} Designation;

void display_designation(Designation desig) {
    switch (desig) {
        case E2F:
            printf("Designation: E2F, Designation String: Software Fresher\n");
            break;
        case E2:
            printf("Designation: E2, Designation String: Software Engineer\n");
            break;
        case E3:
            printf("Designation: E3, Designation String: Senior Software Engineer\n");
            break;
        case E4:
            printf("Designation: E4, Designation String: Team Lead\n");
            break;
        case E5:
            printf("Designation: E5, Designation String: Senior Team Lead\n");
            break;
        default:
            printf("Invalid designation\n");
            break;
    }
}
typedef struct {
    char server_address[100];  
    int port;                  
    char username[50];         
    char password[50];         
    int timeout;              
} PuttyConfig;

void display_putty_config(PuttyConfig config) {
    printf("\nPuTTY Server Configuration:\n");
    printf("Server Address: %s\n", config.server_address);
    printf("Port: %d\n", config.port);
    printf("Username: %s\n", config.username);
    printf("Password: %s\n", config.password);  
    printf("Timeout: %d seconds\n", config.timeout);
}

int main() {
    int desig_input;
    printf("Enter your designation (1-E2F, 2-E2, 3-E3, 4-E4, 5-E5): ");
    scanf("%d", &desig_input);
    Designation desig = (Designation) desig_input;
    display_designation(desig);
    
    PuttyConfig config;
    
    printf("\nEnter the server address: ");
    scanf("%s", config.server_address);
    
    printf("Enter the port number: ");
    scanf("%d", &config.port);
    
    printf("Enter the username: ");
    scanf("%s", config.username);
    
    printf("Enter the password: ");
    scanf("%s", config.password);
    
    printf("Enter the timeout duration (in seconds): ");
    scanf("%d", &config.timeout);
    
    display_putty_config(config);
    
    return 0;
}

