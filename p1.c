#include<stdio.h>

int main()
{
	char taste='g';
	int emptyPlate=10;
	int sFull = 0;

	do
	{printf("\n have a bite of food");
	emptyPlate--;
	printf("\n stomach full (1/0):");
	scanf("%d",&sFull);
	printf("\n how was the food g/b :");
	scanf(" ");
	taste=getchar();
	printf("\n empty plate value:%d",emptyPlate);
	 
	 }while((taste=='g') && (sFull==0) && (emptyPlate>=0));

	 printf ("\n program ended");
	 return 0;
}
