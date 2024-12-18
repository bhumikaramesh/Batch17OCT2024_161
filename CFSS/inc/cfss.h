#ifndef CFSS_H
#define CFSS_H

#include<stdio.h>
#define MAX_BUFF 1024

typedef struct callForwarding
{
	int uId;
	char cfsNumber[MAX_BUFF];
	int cfsActive;
	char serviceType[MAX_BUFF];
	struct callForwarding *next;
}CFSS;


void addCfss(int);
void loadCfss();
int readCfsFile(FILE *,CFSS *);
void writeCfss();
int writeCfsFile(FILE *,CFSS *);
void activateCfss(int,char *,char *);
void deactivateCfss(int);
void unregister(int);
void makeCall(int);

#endif
