#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 16

int main()
{
    char *data1, *data2;
    int i;


    do
    {
        data1 = (char *)malloc(SIZE * sizeof(char));
        if (NULL == data1)
			exit(EXIT_FAILURE);
        printf("Please enter your user name: ");
        scanf("%s", data1);
        if (!strcmp (data1, "quit"))
        {
         /* Valgrind should catch the fact that memory allocated for data1
          * in this iteration is never freed */
            break;
        }
        data2 = (char *)malloc(SIZE * sizeof(char));
        if (NULL == data2)
	{
	    exit(EXIT_FAILURE);
	}
        for (i = 0; i < 16; i++)
        {
            data2[i] = data1[i];
        }
        printf ("data2 :%s:\n", data2);

    /*  Valgrind should catch the fact that memory allocated for data2 is never
     *  freed */
    } while (1);

    return 0;
}


