#include<stdio.h>
#include<stdlib.h>

typedef struct node
	//printf("\nnh1.value=%d and ptr=%d",h1.val,h1.ptr);
{
	int val;
	struct node *ptr;//self referencial pointer(SELF/SRP)
}NODE;

int main()
{
	NODE h1,h2,h3,h4,h5,h6;//creating nodes and allocated them
	NODE *ptr1=NULL;//ptr1 is used to navigate/traverse bw nodes
	h1.val=10;//initialize values to each node
	h1.ptr=NULL;
	h2.val=20;
	h2.ptr=NULL;
	h3.val=30;
	h3.ptr=NULL;


	printf("\naddress of h1=%p",&h1);
	printf("\naddress of h2=%p",&h2);
	printf("\naddress of h3=%p",&h3);
	printf("\naddress of ptr1=%p",&ptr1);
	
	
	printf("\nh1.value=%d and ptr=%p",h1.val,h1.ptr);
	printf("\nh2.value=%d and ptr=%p",h2.val,h2.ptr);
	printf("\nh3.value=%d and ptr=%p",h3.val,h3.ptr);

	printf("\ncontents of ptr1/ptr1 is pointing to :%p",ptr1);

	//making relationship(traverse)/creating lists

	h1.ptr=&h2;
	h2.ptr=&h3;

	//traverse

	ptr1=&h1; // ptr1 pointing to BA of list(first rec)h1
	printf("\n%d",h1.val);
	printf("\n%d",ptr1->val);

//	ptr1=&h2
	ptr1=h1.ptr;
	printf("\n%d",ptr1->val);
//ptr1=&h3;
	ptr1=h2.ptr;//from earlier line 45
	printf("\n%d\n",ptr1->val);

	h4.val=40;//creating new node and initialize values
	h4.ptr=NULL;
	h1.ptr=&h4;//inserting nre node h4 bw h1 and h2
	h4.ptr=&h2;
	h5.val=50;
	h5.ptr=NULL;
	


	h3.ptr=&h5;
	ptr1=&h1;
	printf("\n%d",ptr1->val);

	ptr1=h1.ptr;
	printf("\n%d",ptr1->val);
	
	ptr1=h4.ptr;
	printf("\n%d",ptr1->val);
	
	ptr1=h2.ptr;
	printf("\n%d",ptr1->val);

	ptr1=h3.ptr;
	printf("\n%d",ptr1->val);
	 h6.val=60;
      h6.ptr=NULL;
    h1.ptr=&h6;
	ptr1=&h6;

	
	printf("\n%d",ptr1->val);

	printf("\n\n");

	return 0;
}





