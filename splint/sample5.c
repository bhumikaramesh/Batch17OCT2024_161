#include <stdlib.h>

static int *func();

int main()
{
    int a;
    int *pint = NULL;

    /* Splint should catch the fact that the value of 'a' is used  
     * before being initialized */
    a = a + 1;
    pint = func();
    printf("Value returned by func: %d",*pint);
    return 0;
}
static int *func()
{
    int a = 10;
    /* Splint should catch the fact that the address of 'a' which  
     * is allocated on the stack is being returned to the calling 
     * function
     */
    return &a;
}


