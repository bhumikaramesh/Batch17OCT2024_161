#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
 
#define PORT 9090
 
void menu();
void user_reg();
void user_login();
 
 
struct User {
    long source;
    long desti;
    char name[15];
    char call_s_type;
    char service_s;
    int pin;
};
int pin=123, id =123456,tpin,upin,call_s_type,spin;
FILE *fg;
char tname[10],tcall_s_type[10],tservice_s[10];
long tid,uid,tmobile,tfmob;
 
 
int sock=0;
void menu() {
    int ch;
    printf("\n---------------------------------------------------------\n");
    printf("\n 1. Admin Login \n 2. User Registration \n 3.User Login\n");
    printf(" Enter Your Choice : ");
    scanf("%d", &ch);
    printf("\n---------------------------------------------------------\n");
    switch (ch) {
        case 1:
           // admin_login();
            break;
        case 2:
            user_reg();
            break;
        case 3:
           user_login();
            break;
        default:
            printf("\n Invalid Choice ");
    }
 
}
 
void user_login(){
char c;
        int f=0;
 
        fg = fopen("user.txt","r");
                if(fg == NULL){
                        perror("Error openinf file");
                        exit(EXIT_FAILURE);
                }
 
        printf("\n------------------------------------------------------\n");
        printf("\n.................LOGIN AS USER.........................");
        printf("\n Enter User Id(Source Mobile No.) : ");
        scanf("%ld",&uid);
        printf("\n Enter User Pin : ");
        scanf("%d",&upin);
//        file_exist();
        while((c=getc(fg))!=EOF)
        {
        for(int i=10;i>=EOF;i--)
        while(fscanf(fg,"%ld|%ld|%100[^|]|%100[^|]|%100[^|]|%d%*[\n]",&tmobile,&tfmob,tname,tcall_s_type,tservice_s,&spin) ==6 )
         {
                        if ((uid==tmobile)&&(upin==spin))
                {
                        printf("\n---------------------------------------------\n");
                        printf("\n You are Authentic User\n");
                        printf("\n Login Succuessfully");
                       // call_for();
                        f=1;
                        break;
 
                }
        }
        }
        fclose(fg);
        if(f==1)
        {
        }else
        {
        printf(" You have Entered Invalid User Id Or Pin!!!");
        printf("\n--------------------------------------------------\n");
        printf("Please try Again!!!");
        menu();
        }
 
}
 
void user_reg(){
    struct User newUser;
 
printf("\nEnter source number: ");
    scanf("%ld", &newUser.source);
    printf("Enter destination number: ");
    scanf("%ld", &newUser.desti);
    printf("Enter name: ");
    scanf("%s", newUser.name);
    printf("Enter call forwarding type (U/R/B): ");
    scanf(" %c", &newUser.call_s_type);
    printf("Enter service status (A/D): ");
    scanf(" %c", &newUser.service_s);
    printf("Enter PIN: ");
    scanf("%d", &newUser.pin);
 
   if( send(sock, &newUser, sizeof(struct User), 0)!=sizeof(struct User)){
 
           perror("send");
           exit(EXIT_FAILURE);
 
          }
    printf("Registration successful!\n");
 
}
 
int main() {
    int  valread;
    struct sockaddr_in serv_addr;
 
 
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }
 
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
 
    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
 
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }
 
    menu();
/*    printf("\nEnter source number: ");
    scanf("%ld", &newUser.source);
    printf("Enter destination number: ");
    scanf("%ld", &newUser.desti);
    printf("Enter name: ");
    scanf("%s", newUser.name);
    printf("Enter call forwarding type (U/R/B): ");
    scanf(" %c", &newUser.call_s_type);
    printf("Enter service status (A/D): ");
    scanf(" %c", &newUser.service_s);
    printf("Enter PIN: ");
    scanf("%d", &newUser.pin);
 
    send(sock, &newUser, sizeof(struct User), 0);
    printf("Registration successful!\n");*/
 
    return 0;
}

