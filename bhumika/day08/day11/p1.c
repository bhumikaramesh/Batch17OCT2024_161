#include <stdio.h>
#include <stdlib.h>

int main()
{

	int *ptr=NULL;

	ptr = (int *)malloc(3*sizeof(int));

	free(ptr);
	// free(ptr);
	
	printf("\n\n");

	return 0;
}