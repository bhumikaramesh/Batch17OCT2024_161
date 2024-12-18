#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "library.h"
#include <time.h>
struct  User{
long source;
long desti;
char name[15];
char call_s_type;
char service_s;
int pin;
}user;

int pin=123, id =123456,tpin,upin,call_s_type,spin;
FILE *fg;
char tname[10],tcall_s_type[10],tservice_s[10];
long tid,uid,tmobile,tfmob;
char ess;
void call_for()
{
	int es;
	printf("\n--------------------------------------------------------\n");
	printf("\n Do you want to enable call forwording ?\n ");
	printf("\n1. YES");
	printf("\n2. NO\n");
	printf("\nEnter your choice: ");
	scanf("%d",&es);
	printf("\n--------------------------------------------------------\n");
	switch(es)
	{
	case 1:
		call_type();
		break;	
	case 2:
		printf("You Enter Wrong Choice!!!\n");	
		menu();
		break;
	default:
		printf("INVAILD OPTION");	
}
}

void call_type()
{
	int ch;
	printf("\n....................CALL FORWARDING PAGE.......................");
	printf("\n You can activate your call forwarding ");
	printf("\n  1. 'Unconditional' call fowarding ");
	printf("\n  2. 'No reply' call forwarding ");
	printf("\n  3. 'Busy' call forwarding ");
	printf("\n  4.  Exit ");
	printf("\n Enter your choice : ");
	scanf("%d", &ch);
	printf("\n---------------------------------------------------------------\n");

	switch(ch)
	{
		case 1:
			//user.call_s_type = 'U';
			printf("\n Your 'Unconditional' Service is Enabled ");
			dial();
			break;
		case 2:
		//	user.call_s_type = 'R';
			printf("\n Your 'No Reply' Service is Enabled ");
			dial();
			nor();
			break;

		case 3:
		//	user.call_s_type = 'B';
			printf("\n Your 'Busy' Service is Enabled ");
			dial();
			busy();
			break;
		default:
			printf("\n You Entered Wrong choice");
	}
}
void call(long num)
{	int f=0;
	char c;
	time_t now=time(0);
	char* ti=ctime(&now);
	file_exist();
        while((c=getc(fg))!=EOF)
        {
	
	for(int i=10;i>=EOF;--i)
	{
        while(fscanf(fg,"%ld|%ld|%100[^|]|%100[^|]|%100[^|]|%d%*[\n]",&tmobile,&tfmob,tname,tcall_s_type,tservice_s,&spin)==6 )
        {
        if(tmobile==num)
	printf("\n You are Dialing the Number: %ld\n Your Call is being Forwarded on this Number: %ld\n",tmobile,tfmob);
	//printf("\n Call forwarding at %s :",ti);
	f=1;
	break;
	}
	}
	
	fclose(fg);
        }
	if(f==1)
        {
	printf("\n Call forwarding at %s :",ti);
        }else
        {
        printf("Invalid Number!!!");
	}

}
void nor()
{
	printf("\n Please try Again later!!! User is not Replaying Now \n");
}
void busy()
{
	printf("\n Currently User is Busy!!! Please try Again later\n");
}

void dial()
{	
	int ch;
	long number;
	printf("\n------------------------------------------------------------\n");
	printf("\n press 1 for Dial ");
	printf("\n press 2 for Exit ");
	printf("\n Enter Your Choice : ");
	scanf("%d",&ch);
	printf("\n------------------------------------------------------------\n");
	switch(ch)
	{
		case 1 :
			printf("\n Enter the Number You Want to Call:");
			scanf("%ld",&number);
			call(number);
			break;
		case 2 :
			exit(0);
	}
}
void user_login()
{
	char c;
	int f=0;
	printf("\n------------------------------------------------------\n");
	printf("\n.................LOGIN AS USER.........................");
	printf("\n Enter User Id(Source Mobile No.) : ");
	scanf("%ld",&uid);
	printf("\n Enter User Pin : ");
	scanf("%d",&upin);
	file_exist();
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
			call_for();
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
void admin_login()
{
	printf("\n-------------------------------------------------------\n");
        printf("\n...................LOGIN AS ADMIN.......................");
	printf("\n Enter Admin ID : ");
	scanf("%ld",&tid);
	printf(" Enter Admin Pin : ");
	scanf("%d",&tpin);

	if((tid==id)&&(tpin==pin))
	{
		printf("\n Login as Admin Successfully.....\n");
		admin_menu();
	}
	else
	{
		printf("\n Invalid  Admin ID or Pin Try Again....\n"); 

	}
}
void file_exist()
{
	if ((fg=fopen("user.txt", "r+"))== NULL)
	 {
                		if ( (fg=fopen("user.txt", "w+")) == NULL)
		 {
                    		printf ("Could not open file\n");
                    		exit (1);
                		}
                  }
}
void user_reg()
{
	int f=0;
	char c;
	printf("\n----------------------------------------------------------\n");
	printf("\n................USER REGISTERATION PAGE...................\n");
	printf("\n Enter the Source Number (Mobile Number) : ");
	scanf("%ld", &user.source);

	printf("\n Enter the Destination Number(Forwarded Number) : ");
	scanf("%ld", &user.desti);

	printf("\n Your name: ");
	scanf("%s", user.name);

	printf("\n Your pin : ");
	scanf("%d", &user.pin);
	printf("\n------------------------------------------------\n");
	file_exist();
        while((c=getc(fg))!=EOF)
        {
        for(int i=10;i>=EOF;i--)
        while(fscanf(fg,"%ld|%ld|%100[^|]|%100[^|]|%100[^|]|%d%*[\n]",&tmobile,&tfmob,tname,tcall_s_type,tservice_s,&spin) ==6 )
         {
                        if ((user.source==tmobile))
                {
                        printf("\n---------------------------------------------\n");
                        printf("\n This Source Number is Alreday Registered !!!\n");
			printf("\nTry With Another Source Number");
                        f=1;
			user_reg();
                        break;

                }
        }
        }
        fclose(fg);
        if(f==1)
        {
        }else
        {
	update();
	}
}
	void update(){
	if ( ( fg=fopen("user.txt", "a+")) == NULL) 
	{
                    if ( ( fg=fopen("user.txt", "w+")) == NULL) 
	 {
                        printf ("Could not open file\n");
                        exit ( 1);
                    }
	}	
	ess='D';
	fprintf(fg,"%ld|",user.source);
	fprintf(fg,"%ld|",user.desti);
	fprintf(fg,"%s|",user.name);
	fprintf(fg,"%c|",ess);
	fprintf(fg,"%c|",ess);
	fprintf(fg,"%d",user.pin);
	fprintf(fg," \n");
	fclose(fg);
	printf("\n**********************************************\n");
	printf("\nYou Registered as a User Successfully...");
	printf("\n**********************************************\n");
	menu();
}
void menu()
{
	int ch;
	printf("\n*********************************************************\n");
	printf("\n 1. Admin Login \n 2. Register as User \n 3. User Login \n");
	printf(" Enter Your Choice : ");
	scanf("%d",&ch);
	printf("\n*********************************************************\n");
	switch(ch)
	{
		case 1 :
			admin_login();
			break;
		case 2 :
			user_reg();
			break;
		case 3 :
			user_login();
			break;
		default :
			printf("\n Invalid Choice ");
	}

}
int main()
{	
	 printf("\n---------------------------------------------------------\n");
	printf("\n*************WELCOME TO CALL FORWARDING SYSTEM***********");
	printf("\n---------------------------------------------------------\n");
	menu();
}
