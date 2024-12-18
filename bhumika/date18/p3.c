#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int val;
	struct node *ptr; //Self referencial pointer (SELF/SRP)
}NODE;

void printList(NODE *);
NODE* appendNode(NODE *,NODE *);

int main()
{
	//creating nodes & allocated mem
	NODE h1,h2,h3,h4;

	//ptr1 is used to navigate/travese betwn nodes
	NODE *head=NULL;

	h4.val = 40;
	h4.ptr = NULL;

	head = appendNode(head,&h4);

	//traversing the list
	printList(head);

	
	h1.val = 10;
	h1.ptr = NULL;

	h2.val = 20;
	h2.ptr = NULL;
	h3.val = 30;
	h3.ptr = NULL;

/*	head = appendNode(head,&h1);

	appendNode(head,&h2);
	appendNode(head,&h3);
	*/
	head=addNodeBeg(head,&h1);
	//traversing the list
	printList(head);


	printf("\n\n");

	return 0;

}

void printList(NODE *head)
{
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


 NODE *addNodeBeg(NODE *head,NODE *nn)
 
 {NODE *temp=head;
 if(head==NULL)
 {
 printf("\nLists is empty");
 head=nn;
 temp=nn;
 }
 else
 {
 nn->ptr=head;
 head=nn;//head pointing tothe nn(BA of the new lists)
 }
 return head;//return BA of the list
 }






















