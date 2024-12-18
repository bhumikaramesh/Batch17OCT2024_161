#include <stdio.h>
#include <demostack.h>



//driver code for stack operations
int main()
{
	int v,i;
	/*
	v = pop();
	printf("\n%d element is deleted from the container/stack",v);
	*/

	push(10);
	push(11);
	push(12);
	push(13);
	push(14);
	push(15);
	
	
	displayStack();

	for(i=0;i<MAX;i++)
	{
		v = pop();
		printf("\n%d element is deleted from the container/stack",v);
		displaystack();
	}

	printf("\n\n");

	return 0;

}
