#include <stdio.h>
#include <string.h>
#include <stdlib.h>



typedef struct Employee  
{
	int id;
	int sal;
	int phno;
	char Name[20];
	char Gender;
	struct Employee *next;

}EMP;

int printEmp(EMP *);
int getEmp(EMP *);

int main()
{
	int noEmp;
	int i;

	EMP *e=NULL;
	EMP *temp=NULL;

	// e = &e1;

	printf("\nEnter the Number of Employee Strength: ");
	scanf("%d",&noEmp);

	e = (EMP *)malloc(noEmp*sizeof(EMP));
	temp = e;

/*
	scanf("%d%d%d",&e1.id,&e1.sal,&e1.phno);
	scanf("%s",e1.Name);
	getchar();
	scanf("%c",&e1.Gender);
*/
	for(i=0;i<noEmp;i++,e++)
	{
			getEmp(e);

	}

	e = temp;
	
	for(i=0;i<noEmp;i++,e++)
		printEmp(e);


	
	printf("\n\n");
	e = temp;
	free(e);

	return 0;

}


int getEmp(EMP *e)
{
	printf("\nEnter the Employee Details\n");
	scanf("%d%d%d",&e->id,&e->sal,&e->phno);
	scanf("%s",e->Name);
	getchar();
	scanf("%c",&e->Gender);
}

int printEmp(EMP *e)
{
	printf("\nEmployee Details are\n");
	printf("\n===============================\n");
	printf("\nID: %d",e->id);
	printf("\nName: %s",e->Name);
	printf("\nGender: %c",e->Gender);
	printf("\nPhNo: %d",e->phno);
	printf("\nSalary: %d",e->sal);
	printf("\n===============================\n");

}
