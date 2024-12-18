int push(int v)
{
	if(top == MAX-1)
	{
		printf("\nStack/Container is Full\n");
		return 0;
	}
	top++;
	stackCont[top]= v;
	

	return 0;
}#include <stdio.h>
#include <stdlib.h>
#define MAX 5
typedef struct Employee
{
	int id;
	char name[50];
	float salary
	struct node *next; //Self referencial pointer (SELF/SRP)
}EMP;


struct stack
{
    struct Employee data[MAX];
    int top;
};

void push();
void pop();
void printlist(); 

int push(int EMP)
{
	if(top == MAX-1)
	{
		printf("\nStack/Container is Full\n");
		return 0;
	}
	top++;
	stackCont[top]= v;


	return 0;
}

void printList(EMP *head)
{

	if(head == NULL)
	{
		//the list is empty
		printf("\nList is Empty\n");
		return;
	}
	printf("\nList is\n===================================\n");
	while(head!= NULL)
	{
		printf("%d->",head->val);
		head = head->next;	
	}
	printf("NULL");
	printf("\n\n===================================\n");
}

EMP *appendNode(EMP *head,EMP *nn)
{
	// printf("\nIn appendNode\n");
	EMP *temp = head;

	if(head == NULL)
	{
		//the list is empty
		printf("\nList is Empty\n");
		head = nn;
		temp = nn;
	}
	else
	{
		// printf("\nList is not empty\n");
		while(head->next!= NULL)
		{
			// printf("%d->",head->val);
			head = head->next;
		}

		head->next = nn; //adding node to the end of the list

	}
	head = temp; //head is again pointed to the BA

	return head;
}

EMP *addNodeBeg(EMP *head, EMP *nn)
{
	EMP *temp = head;
	// printf("\nIn addNodeBeg\n");
	if(head == NULL)
	{
		//the list is empty
		printf("\nList is Empty\n");
		head = nn;
		temp = nn;
	}
	else
	{
		nn->next = head;
		head = nn;     // making the head point to the nn(BA of new list)
	}
	return head; //return the BA of the list
}
int delNode(EMP *head, int key)
{
	int flag = 1;

	EMP*temp = head;


	while(head!=NULL)
	{
		if(head->val == key)
		{
			//found
			flag = 0;
			break;
		}
		temp = head;
		head = head->next;
	}	

	if(flag == 0)
	{
		
		temp->next = head->next;
	}

	return flag;


}

void printList(EMP *head)
{

	if(head == NULL)
	{
		//the list is empty
		printf("\nList is Empty\n");
		return;
	}
	printf("\nList is\n===================================\n");
	while(head!= NULL)
	{
		// printf("%d->",head->val);
		printDetails(head);
		head = head->next;
	}
	printf("\nEND OF Records\n");
	printf("\n\n===================================\n");
}
