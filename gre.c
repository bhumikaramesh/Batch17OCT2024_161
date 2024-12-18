#include<stdio.h>
int main()
{
int num1,num2,num3,num4,num5;
printf("enter the numbers");
scanf("%d%d%d%d%d",&num1,&num2,&num3,&num4,&num5);
if(num1>num2&&num1>num3)
{if(num1>num4 && num1>num5)
{
printf("\n%d num1 is greater");
}
else{
printf("num1 is not gretaer");
}
}
if(num2>num1 && num2>num3)
{
if(num2>num4 && num2>num5)
{
printf("\n%d num2 is gretaer");
}
else
{
printf("num2 is not greter");
}
}
if(num3>num1&& num3>num2)

{if(num3>num4 && num3>num5)
{
printf("\n%d num3 is grater");
}

else{
printf("num3 is not greater");
}
}
if(num4>num1 && num4>num2)
{
if(num4>num3 && num4>num5)
{
printf("\n%d num4 is greter");
}
else 
{
printf("num 4 is not gretee");
}}
else
{
if(num5>num1 && num5>num2)
{
if(num5>num3 && num5>num4)
{
printf("\n%d num5 is greter");
}}
else{
printf("no");
}}
}
