#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define BUFF 1024

int main()
{
	int nTc=0;
	char line[BUFF];
	scanf("%d",&nTc);

	char* token=NULL;
	int isCount=0;
	int aCount=0;
	int lenline=0;
	int id1,id3;
	scanf("%d",&nTc);
	
	while(nTc--)
	{
		scanf("%[^\n]s",line);
		fgets(line,BUFF,stdin);
		lenline=str(line);
		printf("\n%c=%d",line(lenline-1)


