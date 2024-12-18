#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CFG 5 // Maximum number of configurations
#define MAX_LEN 50 // Maximum length for name

typedef struct config {
    char *ipaddress;    // pointer to a dotted IP address string
    char name[MAX_LEN]; // server name
    unsigned short port; // port number
} CONFIG;

CONFIG cfgarr_in[MAX_CFG];
CONFIG cfgarr_out[MAX_CFG];

// Function to read and store configuration
int read_store_cfg(CONFIG cfgarr[]) {
    for (int i = 0; i < MAX_CFG; i++) {
        cfgarr[i].ipaddress = (char *)malloc(MAX_LEN * sizeof(char)); // Allocate memory for IP address
        
        printf("Enter configuration for server %d:\n", i + 1);
        printf("Enter IP address: ");
        fgets(cfgarr[i].ipaddress, MAX_LEN, stdin);
        cfgarr[i].ipaddress[strcspn(cfgarr[i].ipaddress, "\n")] = '\0'; // Remove newline

        printf("Enter server name: ");
        fgets(cfgarr[i].name, MAX_LEN, stdin);
        cfgarr[i].name[strcspn(cfgarr[i].name, "\n")] = '\0'; // Remove newline

        printf("Enter port number: ");
        scanf("%hu", &cfgarr[i].port);
        getchar(); // Consume leftover newline character
    }
    return MAX_CFG;
}

// Function to display stored configuration
void display(CONFIG cfgarr[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Server %d:\n", i + 1);
        printf("IP Address: %s\n", cfgarr[i].ipaddress);
        printf("Server Name: %s\n", cfgarr[i].name);
        printf("Port: %hu\n", cfgarr[i].port);
    }
}

int main() {
    // Read and store configuration
    int count = read_store_cfg(cfgarr_in);

    // Display the stored configuration
    display(cfgarr_in, count);

    // Store configuration in binary file
    FILE *outFile = fopen("out.bin", "wb");
    if (outFile == NULL) {
        printf("Error opening file.\n");
        return -1;
    }

    // Write configurations to the binary file
    for (int i = 0; i < count; i++) {
        fwrite(cfgarr_in[i].ipaddress, sizeof(char), MAX_LEN, outFile);
        fwrite(cfgarr_in[i].name, sizeof(char), MAX_LEN, outFile);
        fwrite(&cfgarr_in[i].port, sizeof(unsigned short), 1, outFile);
    }

    // Close the file after writing
    fclose(outFile);

    // Read configuration from the file
    FILE *inFile = fopen("out.bin", "rb");
    if (inFile == NULL) {
        printf("Error opening file.\n");
        return -1;
    }

    // Read and store configurations in cfgarr_out
    for (int i = 0; i < count; i++) {
        cfgarr_out[i].ipaddress = (char *)malloc(MAX_LEN * sizeof(char)); // Allocate memory for IP address
        fread(cfgarr_out[i].ipaddress, sizeof(char), MAX_LEN, inFile);
        fread(cfgarr_out[i].name, sizeof(char), MAX_LEN, inFile);
        fread(&cfgarr_out[i].port, sizeof(unsigned short), 1, inFile);
    }

    // Close the file after reading
    fclose(inFile);

    // Display the read configuration and verify with user input
    display(cfgarr_out, count);

    // Free dynamically allocated memory
    for (int i = 0; i < count; i++) {
        free(cfgarr_in[i].ipaddress);
        free(cfgarr_out[i].ipaddress);
    }

    return 0;
}

