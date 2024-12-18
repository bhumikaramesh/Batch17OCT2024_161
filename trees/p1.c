#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
int data;
struct node *l;
struct node *r;
}NODE;

NODE *createNode(int val)
{
	NODE *nn=(NODE *)malloc(sizeof(NODE));
	nn->data=val;
	nn->l=NULL;
	nn->r=NULL;

	return nn;
}
NODE *insertNode(NODE *root,int val)
{
	if(root==NULL)
	{
		return createNode(val);
	}
	if(root->data<val)
	{
	//right sub tree
	root->r=insertNode(root->r,val);
	}
	else if(root->data>val)
	{
	//left sub tree

	root->l=insertNode(root->l,val);
	}

	else
	{
	//ignore
	printf("\n%d duplicate value found\n",val);

	}
}

void InorderTrav(NODE *root)
{
	if(root==NULL)
	return ;
	InorderTrav(root->l);
	printf("%d ",root->data);
	InorderTrav(root->r);
	}

int main()
{
	NODE *root=NULL;
	root=insertNode(root,5);
	insertNode(root,10);
	insertNode(root,3);
	insertNode(root,4);
	insertNode(root,8);
	insertNode(root,1);
	insertNode(root,2);
	insertNode(root,13);
	printf("\nIn order Traverse\n");
	InorderTrav(root);
	printf("\n\n");
	return 0;


}



















