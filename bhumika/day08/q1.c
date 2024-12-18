#include<stdio.h>
#include<string.h>
g
struct Employee
{
	char Name[20];
	char Gender;
	int ID;
	float Sal;
};

typedef struct Employee EMP;

void getDetails(EMP[],int);
void dispDetails(EMP[],int);
void searchforid(EMP[],int);
void searchforname(EMP[],int);
void searchforsal(EMP[],int count,float min sal,float max sal);
void updatebyname(EMP[],int count,int id,char *newname);
int main()

{
int count=0;
int choice,id;
char ename[50];
float minsalary,maxsalary;

	while(1){
	printf("\n employee details");
	printf("1.scan employee records\n");
	printf("2. display all employee\n");
	printf("3.search for emp id\n");
    printf("4.search by name\n");
	printf("5. search employee with salary\n");
	printf("6. update name\n");
	printf("7. exit\n");
	printf("enter your choice:");
	scanf("%d", &choice);


	switch (choice){

	case 1:
		getdetails(emp,&count;
		break;
	case 2:
		dispdetails(emp,count);
		break;
	case 3:
		printf("enter employee id");
		scanf("%d",id);
		searchforid(emp,count,name);
		break;
	case 4:
 		  printf("enter employee name");
          scanf("%s",name);
          searchforiname(emp,count,name)
		 break;
	case 5:
		minsalary= 6000;
		maxsalry=1000;
		searchforsal(wmp,count,sal);
		break;
	case 6:
		printf("employee id to update"):
		scanf("%d",&id);
		printf("enter new name"):
		scanf("%s",name);
		updateemployeename(emp,count,id,name);
		break;
	case 7:
		printf("exiting program");
		return 0;
	default:
		printf("invalid");
		}
	}
	return 0;
}


void getdetails(employee



















 EMP e1;
 EgetDetails(e,3);
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
		printf("\nSalary: ");
		scanf("%f",&e[i].eSal);

	}
}

void dispDetails(EMP e[],int n)
{
int i;
printf("\n employee details");
for(i=0;i<n;i++)
	printf("\nID:%d",e[i].eID);
	printf("\nName:%d",e[i].eName);
	printf("\nGender:%c",e[i].eGender);
	printf("\nsalary:%d",e[i],e.Sal
}


void searchname(EMP e[],int n)
{
if (name


