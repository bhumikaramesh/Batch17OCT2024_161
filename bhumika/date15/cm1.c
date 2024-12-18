#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Employee
{
	int id;
	int sal;
	int phno;
	char Name[20];
	char Gender;

}EMP;


int display(EMP *);

int main(int argc,char *argv)
{
	int noEmp;
	int i;

	EMP *e=NULL;
	EMP *temp=NULL;
	printf("\nEnter the Number of Employee Strength: ");
	scanf("%d",&noEmp);
	temp = e;
