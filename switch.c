#include<stdio.h>
int main()
{
char clrCode;
clrCode = getc(stdin);
switch(clrCode)
{
	case'B':
	printf("brown");
	break;
	case'g':
	printf("green");
	break;
	case'o':
	printf("Orange");
	break;
	default:
	printf("enter the correct colour");
}
printf("\n program ended\n");
return 0;
}
