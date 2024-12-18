#include<stdio.h>
#include<strings.h>

int main()
{
char name[125];
int age;
float salary;
int designation;
char gender;

printf("enter name");
scanf("%s",&name);

printf("enter age");
scanf("%d",&age);

printf("enter salary");
scanf("%f",&salary);

printf("enter designation (1,2,3,4,5,6)");
scanf("%d",&designation);

printf("enter gender");
getchar();
scanf("%c",&gender);

    printf("\n--- Information Display ---\n");
    printf("name: %s\n", name); 
    printf("Age: %d\n", age);
    printf("Salary: %f\n", salary);  
    printf("Designation : %d\n", designation);
    printf("Gender: %c\n", gender);
return 0;
}

