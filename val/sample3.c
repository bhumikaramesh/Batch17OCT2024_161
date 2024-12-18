#include <stdlib.h>

int *func();

int main()
{
    char *p = NULL;
    int a, i;
    int arr[10];
    int *pint = NULL;
    for (i = 0; i < 10; i++)
    {
        arr[i] = i;
    }

    /* Valgrind does not catch the fact that arr is being accessed out of bounds This is a limitation of the Valgrind tool */
    arr[i+10] = i+10;
    printf ("\nValue of array at location %d : %d ", i+10,     arr[i+10]);
    p = (char *)malloc(sizeof(char)*12);
    
    /* Valgrind should catch the fact that a is accessed without initialization
    */
    a = a + 1;

    /* Valgrind should catch the fact that contents of p are accessed 
     * by printf without being initialized
     */
    printf("\n%s", p);
    strcpy(p, "hello world");
    printf("\n%s", p);
    free(p);

    /* Valgrind should catch the fact that contents of p are accessed 
     * after p has been freed
     */
    strcpy(p, "hello world");
    printf("\n%s", p);
    pint = func();
    printf("Value returned by func: %d",*pint);
    return 0;
}
int *func()
{
    int a = 5;
    /* Valgrind should catch the fact that address of a local variable
     * is returned. This is invalid as the scope and lifetime of a local
     * variable  which is allocated memory from the stack is only till the
     * function returns 
     */
    return &a;
}



