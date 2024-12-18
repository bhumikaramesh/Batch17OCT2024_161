#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 12345
#define BUFFER_SIZE 1024

struct User {
    long source;
    long desti;
    char name[15];
    char call_s_type;
    char service_s;
    int pin;
} user;

int pin = 123, id = 123456, tpin, upin, call_s_type, spin;
FILE *fg;
char tname[10], tcall_s_type[10], tservice_s[10];
long tid, uid, tmobile, tfmob;
char ess;

void call_for() {
    int es;
    printf("\n--------------------------------------------------------\n");
    printf("\n Do you want to enable call forwarding ?\n ");
    printf("\n1. YES");
    printf("\n2. NO\n");
    printf("\nEnter your choice: ");
    scanf("%d", &es);
    printf("\n--------------------------------------------------------\n");
    switch (es) {
        case 1:
            // call_type();
            break;
        case 2:
            printf("You Enter Wrong Choice!!!\n");
            // menu();
            break;
        default:
            printf("INVAILD OPTION");
    }
}

void call(long num) {
    int f = 0;
    char c;
    time_t now = time(0);
    char *ti = ctime(&now);

    while ((c = getc(fg)) != EOF) {
        for (int i = 10; i >= EOF; --i) {
            while (fscanf(fg, "%ld|%ld|%100[^|]|%100[^|]|%100[^|]|%d%*[\n]", &tmobile, &tfmob, tname, tcall_s_type,
                          tservice_s, &spin) == 6) {
                if (tmobile == num)
                    printf("\n You are Dialing the Number: %ld\n Your Call is being Forwarded on this Number: %ld\n",
                           tmobile, tfmob);
                f = 1;
                break;
            }
        }
    }
    fclose(fg);
    if (f == 1) {
        printf("\n Call forwarding at %s :", ti);
    } else {
        printf("Invalid Number!!!");
    }
}

void user_login() {
    char c;
    int f = 0;
    printf("\n------------------------------------------------------\n");
    printf("\n.................LOGIN AS USER.........................");
    printf("\n Enter User Id(Source Mobile No.) : ");
    scanf("%ld", &uid);
    printf("\n Enter User Pin : ");
    scanf("%d", &upin);

    while ((c = getc(fg)) != EOF) {
        for (int i = 10; i >= EOF; i--)
            while (fscanf(fg, "%ld|%ld|%100[^|]|%100[^|]|%100[^|]|%d%*[\n]", &tmobile, &tfmob, tname, tcall_s_type,
                          tservice_s, &spin) == 6) {
                if ((uid == tmobile) && (upin == spin)) {
                    printf("\n---------------------------------------------\n");
                    printf("\n You are Authentic User\n");
                    printf("\n Login Succuessfully");
                    call_for();
                    f = 1;
                    break;

                }
            }
    }
    fclose(fg);
    if (f == 1) {
    } else {
        printf(" You have Entered Invalid User Id Or Pin!!!");
        printf("\n--------------------------------------------------\n");
        printf("Please try Again!!!");
        // menu();
    }
}

void admin_login() {
    printf("\n-------------------------------------------------------\n");
    printf("\n...................LOGIN AS ADMIN.......................");
    printf("\n Enter Admin ID : ");
    scanf("%ld", &tid);
    printf(" Enter Admin Pin : ");
    scanf("%d", &tpin);

    if ((tid == id) && (tpin == pin)) {
        printf("\n Login as Admin Successfully.....\n");
        // admin_menu();
    } else {
        printf("\n Invalid  Admin ID or Pin Try Again....\n");
    }
}

void file_exist() {
    if ((fg = fopen("user.txt", "r+")) == NULL) {
        if ((fg = fopen("user.txt", "w+")) == NULL) {
            printf("Could not open file\n");
            exit(1);
        }
    }
}

void menu() {
    int ch;
    printf("\n*********************************************************\n");
    printf("\n 1. Admin Login \n 2. Register as User \n 3. User Login \n");
    printf(" Enter Your Choice : ");
    scanf("%d", &ch);
    printf("\n*********************************************************\n");
    switch (ch) {
        case 1:
            admin_login();
            break;
        case 2:
            // user_reg();
            break;
        case 3:
            user_login();
            break;
        default:
            printf("\n Invalid Choice ");
    }
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_length = sizeof(client_address);
    char message[] = "Hello, client!\n";
    char buffer[BUFFER_SIZE] = {0};

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Error in socket");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind socket to address and port
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Error in bind");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) < 0) {
        perror("Error in listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d...\n", PORT);

    // Accept incoming connections
    client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_length);
    if (client_socket < 0) {
        perror("Error in accept");
        exit(EXIT_FAILURE);
    }

    printf("Connection established with client\n");

    // Send message to client
    if (send(client_socket, message, strlen(message), 0) < 0) {
        perror("Error in send");
        exit(EXIT_FAILURE);
    }

    // Receive message from client
    if (recv(client_socket, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error in recv");
        exit(EXIT_FAILURE);
    }

    printf("Received from client: %s\n", buffer);

    // Close sockets
    close(client_socket);
    close(server_socket);

    return 0;
}

