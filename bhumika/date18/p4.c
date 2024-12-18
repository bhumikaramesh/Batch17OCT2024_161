#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int val;
	struct node *ptr; //Self referencial pointer (SELF/SRP)
}NODE;

void printList(NODE *);
NODE* appendNode(NODE *,NODE *);
NODE *addNodeBeg(NODE *, NODE *);
int delNode(NODE *, int);


int main()
{
	//creating nodes & allocated mem
	NODE h1,h2,h3,h4;

	//ptr1 is used to navigate/travese betwn nodes
	NODE *head=NULL;

	h4.val = 40;
	h4.ptr = NULL;

	//head = appendNode(head,&h4);

	//traversing the list
	printList(head);

	
	h1.val = 10;
	h1.ptr = NULL;

	h2.val = 20;
	h2.ptr = NULL;
	h3.val = 30;
	h3.ptr = NULL;

	/*head = appendNode(head,&h1);

	appendNode(head,&h2);
	appendNode(head,&h3);
	*/
	head = addNodeBeg(head,&h4);
	//traversing the list
	printList(head);

	head = addNodeBeg(head,&h3);
	//traversing the list
	printList(head);


	head = addNodeBeg(head,&h2);
	//traversing the list
	printList(head);

	head = addNodeBeg(head,&h1);
	//traversing the list
	printList(head);
	
	//head = &h4;

	if(delNode(head,30) == 0)
		printf("\nNode Deleted\n");
	else
		printf("\nKey Not found in the list\n");
	//traversing the list
	printList(head);
	

	printf("\n\n");

	return 0;

}

void printList(NODE *head)
{

	if(head == NULL)
	{
		//the list is empty
		printf("\nList is Empty\n");
		return;
	}
	printf("\nlist using loops and function\n");
	while(head!= NULL)
	{
		printf("%d->",head->val);
		head = head->ptr;	
	}
	printf("NULL");
}

NODE *appendNode(NODE *head,NODE *nn)
{
	printf("\nIn appendNode\n");
	NODE *temp = head;

	if(head == NULL)
	{
		//the list is empty
		printf("\nList is Empty\n");
		head = nn;
		temp = nn;
	}
	else
	{
		printf("\nList is not empty\n");
		while(head->ptr!= NULL)
		{
			printf("%d->",head->val);
			head = head->ptr;	
		}
		
		head->ptr = nn; //adding node to the end of the list
	}
	head = temp; //head is again pointed to the BA

	return head;
}


NODE *addNodeBeg(NODE *head, NODE *nn)
{
	NODE *temp = head;
	printf("\nIn addNodeBeg\n");
	if(head == NULL)
	{
		//the list is empty
		printf("\nList is Empty\n");
		head = nn;
		temp = nn;
	}
	else
	{
		nn->ptr = head;
		head = nn;     // making the head point to the nn(BA of new list)
	}
	return head; //return the BA of the list
}


int delNode(NODE *head, int key)
{
	int flag = 1;

	NODE *temp = head;


	while(head!=NULL)
	{
		if(head->val == key)
		{
			//found
			flag = 0;
			break;
		}
		temp = head;
		head = head->ptr;
	}	

	if(flag == 0)
	{
		printf("\nGunashree->%d",temp->val);
		printf("\nPooja->%d",head->val);
		
		temp->ptr = head->ptr;
	}

	return flag;


}
