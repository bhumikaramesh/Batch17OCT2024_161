#include<stdio.h> int fscanf(FILE *stream, const char *format, ...);

#include<string.h>
#include<stdlib.h>

struct Employees
{
	int id;
	char name[30];
	char gender;
	int phoneno;
	int salary;
};
 
 typedef struct Employee EMP;

int main()
{
FILE *f1;
struct EMP;
int i;
int count=0;


f1=fopen("employee.txt","r");
if(f1==NULL)
{
	printf("error in file opening\n");
	return 1;
}


while(fscanf(f1,"%d|%c|%c|%d|%d",&EMP[count].id,EMP[count].name,&EMP[count].gender,&EMP[count].phoneno,&EMP[count].salary))
{
count++;
}


fclose(f1);


printf("emp data");
for(i=0;i<count;i++)
{
printf("id:%d,name:%s,gender:%c,phoneno:%d,salary:%d",EMP[i].id,EMP[i].name,EMP[i].gender,EMP[i].phoneno,EMP[i].salary);
}
return 0;

}











//read and store it in structure
/*void getDetails(EMP e[], int count)
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
		count++;
	}
}

fclose(f1);

void dispDetails(EMP e[], int count)
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
}*/
