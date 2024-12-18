#include <stdio.h>
int main()
{
int id;
char name[10];
char gender;
long int phonenumber;
double salary;
char designation[5];

printf(" enter the id ");
scanf("%d",&id);
printf("id is %d\n",id);

printf("enter the name ");
scanf("%s",&name);
printf("name is %s\n",name);

printf("enter the gender ");
scanf(" ");
scanf("%c",&gender);
printf("gender is %c\n",gender);

printf("enter the phno ");
scanf("%ld",&phonenumber);
printf("phno is %d\n",phonenumber);

printf("enter salary ");
scanf("%lf",&salary);
printf("salary is %lf\n",salary);

printf("enter the designation ");
scanf("%s",&designation);
printf("desig is %s",designation);

return 0;
}
