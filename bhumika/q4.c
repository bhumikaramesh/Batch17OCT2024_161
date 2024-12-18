#include<stdio.h>
int main()
{
int i,j,rows;
printf("enter the number to define in rows\n");
scanf("%d",&rows);
printf("\n");
for(i=1;i<=rows;i++){
for(j=1;j<=i;j++)
{
printf("*");
}
printf("\n");
}
}
