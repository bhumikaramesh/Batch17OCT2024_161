#include <common.h>
#include <emp.h>

int main()
{
	FILE *fp;
	EMP *e=NULL;
	EMP *temp = NULL;
	char line[BUFF];
	int i;

	system("clear");

	fp = fopen("./data/db.txt","r");

	if(fp == NULL)
	{
		perror("fopen: ");
		return 1;
	}
	e = (EMP *)malloc(5*sizeof(EMP));
	temp = e;

	memset(line,'\0',BUFF);

	while(fgets(line,BUFF,fp)!=NULL)
	{
		line[strlen(line)-1] = '\0';
		e=emp(EMP *)malloc(sizeof(EMP));
		getDetails(e,line);

		e->next=NULL;
		head=appendNode(head,e);
	}

	e = temp;

	for(i=0;i<5;i++,e++){
		// system("clear");
		printDetails(e);

	}
	/*
	while(e!=NULL){
		printDetails(e);
		e++;
	}*/

	printf("\n\n");
	return 0;
}
