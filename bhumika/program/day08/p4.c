/*
while(cond1)
{
	sts
}
*/

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1
#define True 1
#define False 0


int displayMenu();

int main()
{	int n1,n2;
	int ch;
	int flag = 0;
	while(True){
		flag = 0;
		ch = displayMenu();
	printf("enter the numbers");
	scanf("%d %d",&n1,&n2);
		switch(displayMenu())
		{
			case 1:
				printf("\nAddition function executed\n %d ",n1+n2);
				break;
			case 2:
				printf("\nSub function executed\n %d ",n1-n2);
				break;
			case 3:
				printf("\nMul function executed\n %d ",n1*n2);
				break;
			case 4:
				printf("\nDivision function executed\n %d ",n1/n2);
				break;
			case 5:
				printf("\nExiting from the Application\n");
				//exit(SUCCESS);
				flag = 1;
				break;
			default:
				printf("\nEnter the correct Choice\n");

		}//end of switch


		if(flag == 1)
			break;

	}//end of while loop

	printf("\nProgram Ended\n\n");
	return (SUCCESS);
}

int displayMenu()
{
	int choice;

	printf("\nPress,");
	printf("\n1. Addition");
	printf("\n2. Sub");
	printf("\n3. Mul");
	printf("\n4. Division");
	printf("\n5. Exit");
	printf("\nChoice: ");
	scanf("%d",&choice);

	return choice;
}
