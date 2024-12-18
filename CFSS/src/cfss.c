
/****************************************************************************************************
 * FILE NAME    : cfss.c
 *
 * DESCRIPTION  : This file contains function to perform user call forwarding operation
 *
 *******************************************************************************************************/

/*******************************************************************************************************
*                           HEADER FILES
*********************************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<user.h>
#include<cfss.h>

#define PATH "/home2/trainee63/GROUP1/CFSS/data/cfs.dat"

extern CFSS *headCFSS;
extern CFSS *tailCFSS;
extern UD *headUD;
extern UD *tailUD;

/*******************************************************************
 * FUNCTION NAME: addCfss()
 *
 * DESCRIPTION: This function is used to add the user to linked list
 		after signing in.
 *
 * RETURNS      :  returns SUCCESS or FAILURE
 *******************************************************************/

void addCfss(int uid)
{
	CFSS *newCfs = NULL;
	newCfs = (CFSS *)malloc(sizeof(CFSS));
	if(newCfs == NULL)
	{
		printf("\nMemory Allocation failed!");
		exit(EXIT_SUCCESS);
	}
	newCfs->uId = uid;
	newCfs->cfsActive = 0;
	bzero(newCfs->cfsNumber ,MAX_BUFF);/*bzero cleares the buffer */
	memset(newCfs->serviceType,'\0',MAX_BUFF);
	newCfs->next = NULL;
	if(headCFSS == NULL)
	{
		headCFSS = newCfs;
		tailCFSS = newCfs;
	}
	else
	{
		tailCFSS->next = newCfs;
		tailCFSS = newCfs;
	}
}

/*******************************************************************
 * FUNCTION NAME: loadCfss()
 *
 * DESCRIPTION: This function is used to load user details from
 * 		cfs database, and adds them to the linked list.
 *
 * RETURNS      : void.
 *******************************************************************/

void loadCfss()
{
	FILE *fptr = NULL;
	CFSS temp;
	CFSS *newCfs = NULL;
	int flag = 0;

	fptr = fopen(PATH,"r");
	if(fptr == NULL)
	{
		perror("fopen()");
		exit(EXIT_FAILURE);
	}
	while(readCfsFile(fptr,&temp))
	{
		if(flag == 0)
		{
			newCfs = (CFSS *)malloc(sizeof(CFSS));
			if(newCfs == NULL)
			{
				printf("\nMemory Allocation failed!");
				exit(EXIT_FAILURE);
			}
			newCfs->uId = temp.uId;
			strcpy(newCfs->cfsNumber ,  temp.cfsNumber);
			newCfs->cfsActive = temp.cfsActive;
			strcpy(newCfs->serviceType,temp.serviceType);
			newCfs->next = NULL;
			headCFSS = newCfs;
			tailCFSS = newCfs;
			flag = 1;
			continue;
		}
		newCfs = (CFSS *)malloc(sizeof(CFSS));
		if(newCfs == NULL)
		{
			printf("\nMemory Allocation failed");
			exit(EXIT_FAILURE);
		}
		newCfs->uId = temp.uId;
		strcpy(newCfs->cfsNumber , temp.cfsNumber);
		newCfs->cfsActive = temp.cfsActive;
		strcpy(newCfs->serviceType,temp.serviceType);
		newCfs->next = NULL;
		tailCFSS->next = newCfs;
		tailCFSS = newCfs;
	}
	fclose(fptr);
}

/*******************************************************************
 * FUNCTION NAME: readCfsFile()
 *
 * DESCRIPTION: This function is used to read the cfs.dat file.
 *
 * RETURNS      :  returns SUCCESS or FAILURE
 *******************************************************************/

int readCfsFile(FILE *fptr,CFSS *temp)
{
	int ret = fread(temp,sizeof(struct callForwarding),1,fptr);/*returns 1 if fread() fetches the object from the file */

	return ret;
}

/*******************************************************************
 * FUNCTION NAME: writeCfssFile()
 *
 * DESCRIPTION: This function is used to write 
 * 		from the linked  list  
 * 		to the cfs.dat file.
 *
 * RETURNS      :  returns SUCCESS or FAILURE
 *******************************************************************/

void writeCfss()
{
	CFSS *temp = headCFSS;
	FILE *fptr = NULL;
	int retVal = 0;

	fptr = fopen(PATH,"w");
	if(fptr == NULL)
	{
		perror("fopen()");
		exit(EXIT_FAILURE);
	}
	while(temp != NULL)
	{
		retVal = writeCfsFile(fptr,temp);
		if(retVal == 0)
		{
			perror("fwrite()");
			exit(EXIT_FAILURE);
		}
		temp = temp->next;
	}
	fclose(fptr);
}

int writeCfsFile(FILE *fptr,CFSS *temp)
{
	if(temp == NULL)
	{
		return 0;
	}
	if(ftell(fptr)!=0)
	fseek(fptr,0,SEEK_END);
	int ret = fwrite(temp,sizeof(CFSS),1,fptr);
	return ret;
}
/*******************************************************************
 * FUNCTION NAME:activateCfssFile()
 *
 * DESCRIPTION: This function is used to activate the call 
 * 		forwarding service.
 *
 * RETURNS      :void-displays message 
 *******************************************************************/

void activateCfss(int uId,char *cfsNumber,char *serviceType)
{
	CFSS *temp = headCFSS;

	while(temp != NULL)
	{
		if(temp->uId == uId)
		{
				strcpy(temp->cfsNumber , cfsNumber);
				temp->cfsActive = 1;
				strcpy(temp->serviceType,serviceType);
				printf("\nCall forwarding Service Activated to %s successfully!\n\n",temp->serviceType);
				break;
		}
		temp = temp->next;
	}
}
/*******************************************************************
 * FUNCTION NAME:deactivateCfss()
 *
 * DESCRIPTION: This function is used to deactivate the call
 *              forwarding service.
 *
 * RETURNS      :  void- displays message
 *******************************************************************/

void deactivateCfss(int uId)
{
	CFSS *temp = headCFSS;
	
	while(temp != NULL)
	{
		if(temp->uId == uId)
		{
			if(temp->cfsActive != 0)
			{
				temp->cfsActive = 0;
				bzero(temp->cfsNumber , MAX_BUFF);
				memset(temp->serviceType,'\0',MAX_BUFF);
				printf("\nCall Forwarding Service Deactivated Successfully!\n\n");
				break;
			}
			else
			{
				printf("\nYou don't have any activated service!\n\n");
				break;
			}
		}
		temp=temp->next;
	}
}
/*******************************************************************
 * FUNCTION NAME:unregister()
 *
 * DESCRIPTION: This function is used to unregister the call
 *              forwarding service-deletes node.
 *
 * RETURNS      :  void- diplays message
 *******************************************************************/

void unregister(int uId)
{
	UD *userTemp = headUD;
	CFSS *cfsTemp = headCFSS;
	UD *userPrev = headUD;
	CFSS *cfsPrev = headCFSS;

	while(userTemp != NULL)
	{
		if(userTemp->uId == uId)
		{
			if(userTemp->uId == headUD->uId)
			{
				headUD = headUD->next;
				free(userTemp);
				break;
			}
			if(tailUD->uId == userTemp->uId)
			{
				tailUD = userPrev;
				userPrev->next = userTemp->next;
				free(userTemp);
				break;
			}
			userPrev->next = userTemp->next;
			userTemp->next = NULL;
			free(userTemp);
			break;
		}
		userPrev = userTemp;
		userTemp = userTemp->next;
	}

	while(cfsTemp != NULL)
	{
		if(cfsTemp->uId == uId)
		{
			if(cfsTemp->uId == headCFSS->uId)
			{
				headCFSS = headCFSS->next;
				free(cfsTemp);
				break;
			}
			if(tailCFSS->uId == cfsTemp->uId)
			{
				tailCFSS = cfsPrev;
				cfsPrev->next = cfsTemp->next;
				free(cfsTemp);
				break;
			}
			cfsPrev->next = cfsTemp->next;
			cfsTemp->next = NULL;
			free(cfsTemp);
			break;
		}
		cfsPrev = cfsTemp;
		cfsTemp = cfsTemp->next;
	}
	printf("\nYou have been unregistered successfully!\n\n");
}
/*******************************************************************
 * FUNCTION NAME:makeCall()
 *
 * DESCRIPTION: This function is used to make a call
 *              to a provided number, and through a service.
 *
 * RETURNS      :  void- diplays message
 *******************************************************************/

void makeCall(int uId)
{
	CFSS *temp = headCFSS;

	while(temp != NULL)
	{
		if(temp->uId == uId)
		{
			if(temp->cfsActive == 1)
			{
				printf("\nCall Forwarding is Active!\n\n");
				printf("\nCall has been forwarded to %s with %s service\n\n ",temp->cfsNumber,temp->serviceType);
				break;
			}
			else
			{
				printf("\nNo active call forwarding service.\nNormal Call to the client\n\n");
				break;
			}
		}
		temp = temp->next;
	}
}
