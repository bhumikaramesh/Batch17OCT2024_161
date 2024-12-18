#include<stdio.h>
int main()
{
int n,itr;
printf("enter the value:");
scanf("%d",&n);
for(itr=1;itr<n;itr++)
{
printf("%d,",(itr*itr)-1);
}
printf("%d",(itr*itr)-1);

printf("\n\n");
return 0;
}
