#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Employee
{
	int id ;
	float sal;
	char g;
	char name[20];
}sEMP;

typedef union Employees
{
	 int id;
	 float sal;
	 char g;
	 char name[20];

}uEMP;

int main()
{
	sEMP es;
	uEMP eu;

	printf("\n size of struct=%d",sizeof(es));
	printf("\n size of union=%d",sizeof(eu));

	eu.id=101;
	eu.sal=10000;
	strcpy(eu.name,"bhumika");
	printf("\n name =%s \n",eu.name);

	return 0;
	}




