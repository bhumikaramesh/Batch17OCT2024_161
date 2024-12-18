/*
else if ladder

if(cond1)
{
	
}
else if(cond2)
{
	
}
else if(cond3)
{
	
}
else
{
	
}

*/

#include <stdio.h>

int main()
{
	char clrCode;

	clrCode = getchar();

	if(clrCode == 'B')
		printf("\nBlack\n");
	else if(clrCode == 'N')
		printf("\nBrown\n");
	else if(clrCode == 'R')
		printf("\nRed\n");
	else if(clrCode == 'O')
		printf("\nOrange\n");
	else
		printf("\nEnter the correct colour code");

	printf("\nProgram Ended\n");

	return 0;
}