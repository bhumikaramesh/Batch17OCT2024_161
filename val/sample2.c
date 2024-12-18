#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 16

int main()
{
    char *data1, *data2, *tmp;
    int i=10;

    data1 = (char *)malloc(SIZE * sizeof(char));
  if (NULL == data1)
        exit(EXIT_FAILURE);

    printf("Please input your username: ");
    scanf("%s", data1);
    data2 = (char *)malloc(SIZE * sizeof(char));
    if (NULL == data2)
         exit(EXIT_FAILURE);
    tmp = data1;
    for (i = 0; i<16; i++)
    {
        data2[i] = *(tmp++);
    }
    printf ("data2 :%s:\n", data2);

    /* Valgrind should catch the fact that memory pointed to by tmp is not a 
     * valid memory */
    printf ("tmp :%s:\n", tmp);
    free(data1);
    free(data2);
 return 0;
}


