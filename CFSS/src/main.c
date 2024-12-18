/****************************************************************************************************
 * FILE NAME       : main.c
 *
 * DESCRIPTION     : This file contains main function which calls all other functions to
 *                   perform required operations
                 
 *******************************************************************************************************/

/*******************************************************************************************************
*                           HEADER FILES
*********************************************************************************************************/

#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<common.h>
#include<cfss.h>
#include<user.h>

int main()
{
	int choice = 0;
	int flag = 1;
	int flag1 = 1;
	int ch = 1;
	int uid = 0;
	int temp = 0;
	char number [MAX_BUFF]={'\0',};
	char uName[MAX_BUFF]={'\0',};
	char pNumber [MAX_BUFF] = {'\0',};

	loadPDetails();/*loads user details from file and stores in the linked list */
	loadCfss();/* This function is used to load user details from cfs database, and adds them to the linked list.*/
	while(1)
	{
			switch(initialScreen())
			{
				case 1:
					signUp();
					sleep(2);
					break;
				case 2:
					uid = signIn();
					sleep(2);
					if(uid == -1)
					{
						continue;
					}
					else
					{
						searchUser(uid,uName);
						searchPhoneNumber(uid,pNumber);
						flag = 1;
						while(flag)
						{
							choice = mainScreen(uName);
							switch(choice)
							{
								case 1:
									flag1 = 1;
									temp = 0;
									while(flag1)
									{
										printf("\nEnter Call Forwarding Number: ");
										bzero(number,MAX_BUFF);
										scanf(" ");
										fgets(number,MAX_BUFF,stdin);
										number[strlen(number)-1]='\0';
										temp=checkSamePNumber(pNumber,number);
										if(temp!=-1)
										{
											flag1 = 0;

										}
									
									}

									ch=1;
									while(ch)
									{
										choice = cfsScreen();
										if(choice == 1)
										{
									
											activateCfss(uid,number,"Unconditional");
											ch = 0;
										}
										else if(choice == 2)
										{
											activateCfss(uid,number,"No Reply");
											ch = 0;
										}
										else if(choice == 3)
										{
											activateCfss(uid,number,"Busy");
											ch = 0;
										}
										else
										{
											printf("\nEnter correct choice!");
										}
									}
									sleep(2);
									break;
								case 2:
									deactivateCfss(uid);
									sleep(5);
									break;
								case 3:
									unregister(uid);
									sleep(3);
									uid = 0;
									flag = 0;
									break;
								case 4:
									makeCall(uid);
									sleep(4);
									break;
								case 5:
									uid = 0;
									flag = 0;
									printf("\nLogged Out Successfully!\n\n");
									sleep(2);
									break;
								case 6:
									writePDetails();
									writeCfss();
									freeUd();
									freeCfs();
									printf("\n\t\t*****************THANK YOU***************\n");
									sleep(2);
								
									system("clear");
									exit(0);
								default:
									sleep(2);
									break;

							}
						}
					}
					break;
				case 3:
					writePDetails();
					writeCfss();
					freeUd();
					freeCfs();
					printf("\n\t\t************************THANK YOU***********************\n");
					sleep(2);
                                	system("clear");
					exit(0);
				default:
					sleep(2);
					break;
			}
		}
	return 0;
}
