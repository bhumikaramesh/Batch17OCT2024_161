/*
demo on structures

*/

#include <stdio.h>
#include <string.h>

struct Employee
{
	char eName[20];
	char eGender;
	char eAddress[20];
	int eId;
	float eSal;
};

typedef struct Employee EMP;


void getDetails(EMP [],int);
void dispDetails(EMP [], int);


int main()
{

	EMP e1;
	EMP e[3];
	int i;

/*
	e1.eId = 101;
	e1.eSal = 10000.1;
	strcpy(e1.eName,"Bhima");
	strcpy(e1.eAddress,"KAR");
	e1.eGender = 'M';


	printf("\nEmployee Details are\n");
	printf("\nID: %d",e1.eId);
	printf("\nName: %s",e1.eName);
	printf("\nGender: %c",e1.eGender);
	printf("\nAddress: %s",e1.eAddress);
	printf("\nSalary: %f",e1.eSal);

*/
	getDetails(e,3);
	dispDetails(e,3);

	

	printf("\n\n");
	return 0;

}

void getDetails(EMP e[], int n)
{
	int i;

	printf("\nEnter Employee Details\n");
	for(i=0;i<n;i++)
	{
		printf("\nName: ");
		scanf("%s",e[i].eName);
		printf("\nID: ");
		scanf("%d",&e[i].eId);
		printf("\nGender: ");
		scanf(" ");
		scanf("%c",&e[i].eGender);
		printf("\nAddress: ");
		scanf("%s",e[i].eAddress);
		printf("\nSalary: ");
		scanf("%f",&e[i].eSal);

	}
}

void dispDetails(EMP e[], int n)
{
	int i;
	printf("\nEmployee Details are\n");
	for(i=0;i<n;i++){
		printf("\n=========================\n");
		printf("\nID: %d",e[i].eId);
		printf("\nName: %s",e[i].eName);
		printf("\nGender: %c",e[i].eGender);
		printf("\nAddress: %s",e[i].eAddress);
		printf("\nSalary: %f",e[i].eSal);
		printf("\n=========================\n");
	}
}
