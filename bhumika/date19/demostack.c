#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int bottom = -1;//array starts from 0
int top=0;//initially

int push(int );
int pop();
int stackCount[MAX];

int push(int v)
{
	if(top==MAX-1)
	{
		printf("\nstack is full");
		return 0;

	}
	stackCount[top]=v;
	top++;
}
int pop()
{	int v;
	if(top==bottom)
	{
		printf("\nstack is empty");
		return 0;
	}
	v=stackCount[top];
	top--;
	return v;

}

void displayStack()
{
	int iter;
	if(top==bottom)
        {
           printf("\nstack is empty");
           return ;
           }
		 printf("\nStackelemets are");
	for(iter=top;iter>-1;iter--)
	{
		printf("\n%d",stackCount[iter]);

	}
	printf("\n\n");
}


