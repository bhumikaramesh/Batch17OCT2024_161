/*

Loop:

1. initialze variable
2. cond check
3. sts to be executed
4. Counter

3 types:

1. do while
2. while
3. for 

two types of loop

1. entry controled
2. exit controled


do{
	
	sts
}while(cond);


*/

#include <stdio.h>

int main()
{
	char taste='g';
	int emptyPlate=5;
	int sFull = 0;


	do
	{
		printf("\nHave a Bite of food\n");
		emptyPlate--;
		printf("\nStomach Full (1/0): ");
		scanf("%d",&sFull);
		printf("\nHow was the taste (g/b): ");
		scanf(" ");
		taste = getchar();
		printf("\nEmpty Plate Value: %d",emptyPlate);
	}while((taste=='g') && (sFull==0) && (emptyPlate>=0));

	printf("\nProgram Ended\n");
	return 0;
}
