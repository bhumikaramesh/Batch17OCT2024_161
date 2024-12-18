#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 16

int main()
{
    char *data1;
    char *data2;
    int i;
    int a;


    do
    {
        data1 = (char *)malloc(SIZE);
        printf("Please enter your user name: ");

        /* Splint should catch the fact that data1 may not have been allocated
         * memory */
 
        scanf("%s", data1);
	a=strcmp (data1, "quit");
	if(a != 0)
        {
            break;
        }
        data2 = (char *)malloc(SIZE);
        data2[0] = '\0'; /* Added just to avoid false alarm by splint about data 2 not being defined ! */
        for (i = 0; i < 16; i++)
        {
             /* Splint should catch the fact that data2 may not have been
              * allocated memory */
            data2[i] = data1[i];
        }
        free (data1);
        printf ("data2 :%s:\n", data2);
	free(data2);
    } while (1);

    /* Splint should catch the fact that the memory allocated for 
     * data2 is not freed */
    return 0;
}


