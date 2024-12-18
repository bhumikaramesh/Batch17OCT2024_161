/****************************************************************************************************
 * FILE NAME    : common.c
 *
 * DESCRIPTION  : This file contails function definition required to perform call forwarding services
 *                
 *
 *
 *******************************************************************************************************/


/***************************************************************************
*                           HEADER FILES
*****************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<common.h>
#include<user.h>
#include<cfss.h>


/***************************************************************************
*                          GLOBAL VARIABLES TAKEN USING EXTERN
*****************************************************************************/

extern UD *headUD;
extern UD *tailUD;
extern CFSS *headCFSS;
extern CFSS *tailCFSS;

/*******************************************************************
 **  FUNCTION_NAME  :   signUp
 **
 **  DESCRIPTION    :   This function takes user details and
                        store it in the database
 **
 **  RETURN_TYPE    :   returns success or failure
 ********************************************************************/

void signUp()
{
	UD *newUser = NULL;

	newUser = getPDetails();
	if(newUser == NULL)
	{
		return;
	}
	else
	{
		if(headUD == NULL)
		{
			newUser->uId = 1;
			headUD = newUser;
			tailUD = newUser;
		}
		else
		{
			newUser->uId = (tailUD->uId) + 1;
			tailUD->next = newUser;
			tailUD = newUser;
		}
		addCfss(newUser->uId);
		printf("\nYou have been registered successfully!\n\n");
	}
}

/**********************************************************************
 **  FUNCTION_NAME  :   signIn
 **
 **  DESCRIPTION    :   This function takes phone number  and password
 			and if credentials match, the user logs in 
			to the system.
                        
 **
 **  RETURN_TYPE    :   returns success or failure
 ***********************************************************************/

int signIn()
{
	char pNumber[MAX_BUFF] = {'\0',};
	char passwd[MAX_BUFF] = {'\0',};
	int uid = 0;

	printf("\nEnter phone number: ");
	scanf(" ");
	fgets(pNumber,MAX_BUFF,stdin);
	pNumber[strlen(pNumber)-1] = '\0';
	printf("\nEnter Password: ");
	scanf(" ");
	fgets(passwd,MAX_BUFF,stdin);
	passwd[strlen(passwd)-1] = '\0';
	uid = checkCred(pNumber,passwd);
	if(uid > 0)
	{
		printf("\nLogged In Successfully!\n\n");
		return uid;
	}
	printf("\nEither Phone number or Password is Incorrect!Try Again.\n\n");
	return -1;
}

/*******************************************************************
 **  FUNCTION_NAME  :   checkCred
 **
 **  DESCRIPTION    :   This function checks whether user name and
 			password match or not.
                        
 **
 **  RETURN_TYPE    :   returns success or failure
 ********************************************************************/

int checkCred(char *pNumber,char *passwd)
{
	int flag = 0;
	int uid = 0;
	UD *temp = headUD;


	while(temp != NULL)
	{
		if(strcmp(temp->pNumber,pNumber) == 0)
		{
			flag += 1;
			if(strcmp(temp->passwd,passwd) == 0)
			{
				flag += 1;
				uid = temp->uId;
				break;
			}
			else
			{
				break;
			}
		}
		temp = temp->next;
	}
	if(flag == 2)
	{
		return uid;
	}
	return 0;
}

/*******************************************************************
 **  FUNCTION_NAME  :   initialScreen()
 **
 **  DESCRIPTION    :   This function is used to display the
 			initial login screen.
 **
 **  RETURN_TYPE    :   returns choice
 ********************************************************************/


int initialScreen()
{
	int choice =0;
	
	system("clear");
	printf("*******************Welcome To Call Forwarding System Simulator*********************");
	printf("\n\n");
	printf("Press,");
	printf("\n1. To SignUp");
	printf("\n2. To SignIn");
	printf("\n3. To Exit");
	printf("\n");
	printf("***********************************************************************************");
	printf("\nEnter your choice: ");
	scanf("%d",&choice);
	return choice;
}


/***********************************************************************
 **  FUNCTION_NAME  :   mainScreen
 **
 **  DESCRIPTION    :   This function takes the first name of
 			the user, and also displays the next menu 
			after the initial screen.
 **
 **  RETURN_TYPE    :   returns choice
 ************************************************************************/

int mainScreen(char *fName)
{
	int choice = 0;
	system("clear");

	printf("***********************Welcome\t%s****************************",fName);
	printf("\n\n");
	printf("Press,");
	printf("\n1. To Activate Call Forwarding Service");
	printf("\n2. To Deactivate Call Forwarding Service");
	printf("\n3. To Unregister");
	printf("\n4. Make a call");
	printf("\n5. Log Out");
	printf("\n6. Exit Application");
	printf("\n");
	printf("****************************************************************");
	printf("\nEnter your choice: ");
	scanf("%d",&choice);
	return choice;
}

/***********************************************************************
 **  FUNCTION_NAME  :   cfsScreen
 **
 **  DESCRIPTION    :   This function allows the user to choose 
 **			the type of call forwarding service he wants.

 **  RETURN_TYPE    :   returns choice
 ************************************************************************/

int cfsScreen()
{
	int choice = 0;

	system("clear");
	printf("Press,");
	printf("\n1. Unconditional");
	printf("\n2. No Reply");
	printf("\n3. Busy");
	printf("\n\n");
	printf("Enter your choice: ");
	scanf("%d",&choice);
	return choice;
}
/*******************************************************************
 **  FUNCTION_NAME  :   searchUser
 **
 **  DESCRIPTION    :   This function searches the first name 
 			based on uid, that it takes as input.
 **
 **  RETURN_TYPE    :   returns void
 ********************************************************************/

void  searchUser(int uid,char *fName)
{
	UD *temp = headUD;

	while(temp != NULL)
	{
		if(temp->uId == uid)
		{
			strcpy(fName,temp->fName);
			break;
		}
		temp = temp->next;
	}
}

void  searchPhoneNumber(int uid,char *pNumber)
{
        UD *temp = headUD;

        while(temp != NULL)
        {
                if(temp->uId == uid)
                {
                        strcpy(pNumber,temp->pNumber);
                        break;
                }
                temp = temp->next;
        }
}



void freeUd()
{
	UD *temp = headUD;
	while(temp != NULL)
	{
		temp = temp->next;
		free(headUD);
		headUD = temp;
	}
}

void freeCfs()
{
	CFSS *temp = headCFSS;
	while(temp != NULL)
	{
		temp = temp->next;
		free(headCFSS);
		headCFSS = temp;
	}
}
