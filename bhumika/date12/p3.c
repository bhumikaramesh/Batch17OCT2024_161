#include<common.h>
#include <emp.h>

int getdetails(EMP e*,char line[])
{
char *token = NULL;
token =strtok(line,"|");
if(token == NULL)
{
	e->id = atoi(token);
	token = strtok(NULL,"|");
	strcpy(e->Name,token);
	token = strtok(NULL,"|");
	e->g=*token;


