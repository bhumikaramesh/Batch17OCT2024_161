#ifndef USER_H
#define USER_H

#include<stdio.h>
#define MAX_BUFF 1024

typedef struct userDetails
{
	char fName[MAX_BUFF];
	char lName[MAX_BUFF];
	char gender;
	char pNumber[MAX_BUFF];
	char uName[MAX_BUFF];
	int uId;
	char passwd[MAX_BUFF];
	struct userDetails *next;
}UD;


UD *getPDetails();
void loadPDetails();
int readUserFile(FILE *,UD *);
void writePDetails();
int writeUserFile(FILE *,UD *);
int checkName(char *);
int checkGender(char);
int checkPhoneNumber(char *);
int checkSamePNumber(char *, char *);
int checkValidPhone(char *phone_number);

#endif
