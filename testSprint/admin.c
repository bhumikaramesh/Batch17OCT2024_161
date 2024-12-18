#include "library.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#define FILENAME_SIZE 1000
#define MAX 2048
char ttname[10],ttcall_s_type[10],ttservice_s[10];
long ttmobile,ttfmob;
int tspin;
void file_existence();
FILE *ffg;
void update_database(){
	int chh;
	printf("\n.....................DISPLAYING PAGE...........................\n");
	printf("\n 1.All User Data \n 2.Particular User's Data\n");
	printf("Enter Your Choice: ");
	scanf("%d",&chh);
	printf("\n---------------------------------------------------------------\n");
	switch(chh)	
	{
	case 1:
	dis();
	admin_menu();
	break;
	case 2:
	display();
	break;
	default:
	printf("You Entered Invaild Option");
	admin_menu();
	}
}
void display(){
	long s;
	int f=0;
	printf("Enter the Unique Id(Source):");
	scanf("%ld",&s);
 	char c;
        file_existence();
        while((c=getc(ffg))!=EOF)
   {
        while(fscanf(ffg,"%ld|%ld|%100[^|]|%100[^|]|%100[^|]|%d%*[\n]",&ttmobile,&ttfmob,ttname,ttcall_s_type,ttservice_s,&tspin)==6 )
        {
 	     if(s==ttmobile)
	{
	printf("******************************************");
	printf("Source Number:%ld\n",ttmobile);
	printf("Destination Number:%ld\n",ttfmob);
	printf("User Name:%s\n",ttname);
	printf("User Pin: %d\n",tspin);
	printf("User's Call Forwarding Type:%s\n",ttcall_s_type);
	printf("User's Service Status:%s\n",ttservice_s);
	printf("*******************************************");
	admin_menu();
	f=1;
	break;
	}
	}
    }
	if(f==1)
	{
	}else{
	printf("You Enter Invaild Source Number\n Data is not Present in Our Database");
    }
}
void dis()
{
        char c;
	int co=1;
        file_existence();
        while((c=getc(ffg))!=EOF)
     {
        for(int i=10;i>EOF;i--)
	{
        while(fscanf(ffg,"%ld|%ld|%100[^|]|%100[^|]|%100[^|]|%d%*[\n]",&ttmobile,&ttfmob,ttname,ttcall_s_type,ttservice_s,&tspin)==6 )
        {
	
	printf("\n****************INDEX NUMBER:%d***************",co);
        printf("\nSource Number:%ld\n",ttmobile);
        printf("Destination Number:%ld\n",ttfmob);
        printf("User Name:%s\n",ttname);
        printf("User Pin :%d\n",tspin);
	printf("User's Call Forwarding Type:%s\n",ttcall_s_type);
        printf("User's Service Status:%s\n",ttservice_s);
     	printf("**********************************************\n");
	co+=1;
	}
	}
     }

}
void add(){
	printf("--------------------To Add NEW User------------------");
	user_reg();
	admin_menu();	
}
void file_existence()
{
       if ((ffg=fopen("user.txt", "r+"))== NULL)
        {
          if ( (ffg=fopen("user.txt", "w+")) == NULL)
        	{
        	   printf ("Could not open file\n");
 	           exit(1);             
	  	}
        }
}

int unregister_user(){
printf("\n.....................TO UNREGISTER THE USER..................\n");
{
          int lno, ctr = 0;
          char ch;
          FILE *fptr1, *fptr2;
	  char fname[MAX];
          char str[MAX], temp[] = "temp.txt";
	  printf("\n\n Delete a specific line from a file :\n");
	  printf("-----------------------------------------\n"); 
 	  printf(" Input the file name to be opened(user.txt) : ");
	  scanf("%s",fname);	
	  dis();	
       	  fptr1 = fopen(fname, "r");
          if (!fptr1) 
		{
                printf(" File not found or unable to open the input file!!\n");
                return 0;
        	}
         fptr2 = fopen(temp, "w"); // open the temporary file in write mode 
         if (!fptr2) 
		{
                printf("Unable to open a temporary file to write!!\n");
                fclose(fptr1);
                return 0;
        	}
	file_existence();
        printf("\n Input the Index Number you want to remove : ");
        scanf("%d", &lno);
	//	lno++;
        // copy all contents to the temporary file except the specific line
        while (!feof(fptr1)) 
        {
            strcpy(str, "\0");
            fgets(str, MAX, fptr1);
            if (!feof(fptr1)) 
            {
                ctr++;
                /* skip the line at given line number */
                if (ctr != lno) 
                {
                    fprintf(fptr2, "%s", str);
                }
            }
        }
        fclose(fptr1);
        fclose(fptr2);
        remove(fname);  		// remove the original file 
        rename(temp, fname);
   	  dis();
	printf("\n-----------------------------------------------------\n");
	printf("\n You Deleted %d Index Data Successfully!!!",lno);
        return 0;
}
}

void admin_menu(){
int Achoice;
printf("\n.......................ADMIN MENU......................\n");
//printf("\nwelocme to menu:");
//printf("\n......");
printf("\n 1. Add User");
printf("\n 2. Update & Display the Database");
printf("\n 3. Delete the Database(Unregister User)");
printf("\n 4. Home");
printf("\n Enter your Choice:");
scanf("%d",&Achoice);
printf("\n-----------------------------------------------------\n");
switch(Achoice)
{
case 1:
add();
break;
case 2:
update_database();
break;
case 3:
unregister_user();
break;
case 4:
menu();
break;
default:
printf("\n You Enter Wrong Choice Try Again!!!");
exit(0);
break;
}
}


