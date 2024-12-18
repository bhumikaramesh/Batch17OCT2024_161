#include <stdio.h>
#include <stdlib.h>
int main()
{
    int * p = (int*) malloc(sizeof(int) * 3);
    if (NULL == p)
		exit (EXIT_FAILURE);
   *p = 1;
   *(p+1) = 2;
   *(p+2) = 3;
    
   /* Valgrind should catch the fact that the memory allocated to p is 
    * being accessed out of bounds in the following 2 statements */
   *(p+3) = 4;
   *(p+100) = 4;
    free(p);
}
