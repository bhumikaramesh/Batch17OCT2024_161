#include <stdio.h>
#include <string.h>

typedef struct {
    char server_address[100];  
    int port;                
    char username[50];       
    char password[50];     
    int timeout;               
    int use_ssh;
    char session_name[50];     
} PuttyConfig;

void display_putty_config(PuttyConfig config) {
    printf("\nPuTTY Server Configuration:\n");
    printf("Server Address: %s\n", config.server_address);
    printf("Port: %d\n", config.port);
    printf("Username: %s\n", config.username);
    printf("Password: %s\n", config.password);  
    printf("Timeout: %d seconds\n", config.timeout);
    printf("Use SSH: %s\n", config.use_ssh ? "Yes" : "No");
    printf("Session Name: %s\n", config.session_name);
}

int main() {
    PuttyConfig config;

    printf("Enter the server address: ");
    scanf("%s", config.server_address);
    
    printf("Enter the port number: ");
    scanf("%d", &config.port);
    
    printf("Enter the username: ");
    scanf("%s", config.username);
    
    printf("Enter the password: ");
	scanf("%s", config.password);  
    
    printf("Enter the timeout duration (in seconds): ");
    scanf("%d", &config.timeout);
    
    printf("Do you want to use SSH? (1 for Yes, 0 for No): ");
    scanf("%d", &config.use_ssh);
    
    printf("Enter the session name: ");
    scanf("%s", config.session_name);
    
    display_putty_config(config);

    return 0;
}

