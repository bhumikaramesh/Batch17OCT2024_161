#ifndef COMMON_H
#define COMMON_H


void signUp();
int signIn();
int checkCred(char *,char *); 
int initialScreen();
int mainScreen(char *);
int cfsScreen();
void searchUser(int,char *);
void searchPhoneNumber(int, char *);
void freeUd();
void freeCfs();

#endif
