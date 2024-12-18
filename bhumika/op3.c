#include <stdio.h>

int main()
{
int num;
printf("enter the decimal number");
scanf("%d",&num);

if(num>0 || num>127)
{
printf("hexadecimal value is %02X\n",num);
}
else
{
printf("invalid input");
}
return 0;
}
