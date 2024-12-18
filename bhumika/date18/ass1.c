
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int val;
	struct node *next; //Self referencial pointer (SELF/SRP)
}EMP;


EMP *createNode(EMP *);
int dispMainMenu();
void printList(EMP *);
EMP* appendNode(EMP *,EMP *);
EMP *addNodeBeg(EMP *, EMP *);
int delNode(EMP *, int);


int main()
{
	EMP *nn=NULL;
	EMP *head=NULL,*temp=NULL;
	int flag=0;
	int key=0;

	while(1)
	{
		switch(dispMainMenu())
		{
			case 1:
					nn = createNode(nn);
					head = addNodeBeg(head,nn);
					break;
			case 2:
					nn = createNode(nn);
					head = appendNode(head,nn);
					break;
			case 3:
					printf("\nEnter the key of the node: ");
					scanf("%d",&key);
					delNode(head,key);
					break;
			case 4:
					printList(head);
					break;
			case 5:
					flag = 1;
					break;
			default:
					printf("\nEnter the correct Choice");
					break;
		}
		if(flag == 1)
			break;
	}
	
	printf("\n\n");

	return 0;

}

EMP *createNode(EMP *nn)
{
	nn = (EMP *)malloc(sizeof(EMP));
	printf("\nEnter the value of New Node: ");
	scanf("%d",&nn->val);
	nn->next = NULL;
	return nn;
}


int dispMainMenu()
{
	int ch;
	printf("\nLinked List Menu\n");
	printf("\nPress,");
	printf("\n1. Add Node in Begning");
	printf("\n2. Add Node to the End");
	printf("\n3. Delete a Node");
	printf("\n4. Print List");
	printf("\n5. Exit");
	printf("\nChoice: ");
	scanf("%d",&ch);

	return ch;
}


int getDetails(EMP *e, char line[])
{
	char *token = NULL;
	token = strtok(line,"|");
	if(token != NULL)
	{
		e->id = atoi(token);
		token = strtok(NULL,"|");
		strcpy(e->Name,token);
		token = strtok(NULL,"|");
		e->g = *token;
		token = strtok(NULL,"|");
		e->phno = atoi(token);
		token = strtok(NULL,"|");
		e->sal = atoi(token);
		return 0;
	}
	return 1;
}

int printDetails(EMP *e)
{
	printf("\nEmployee Details are\n");
	printf("\n===============================\n");
	printf("\nID: %d",e->id);
	printf("\nName: %s",e->Name);
	printf("\nGender: %c",e->g);
	printf("\nPhNo: %d",e->phno);
	printf("\nSalary: %d",e->sal);
	printf("\n===============================\n");
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
