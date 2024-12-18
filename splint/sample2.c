#include <stdio.h>

int main()
{
	int *p;

	/* Splint should catch the fact that the storage pointed to by 
     * p is not yet defined
	 */ 
	printf ("integer value : %d", *p);
	return 0;
}

