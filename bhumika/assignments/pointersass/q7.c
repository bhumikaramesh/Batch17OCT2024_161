#include <stdio.h>
#include <stdlib.h>

int main()
{
    char arr[] = "ABC";
	
    char *ptr = (char*)&arr;
    printf("%p %p", arr, ptr);
    printf("\n 1 %c %c", *ptr, *(ptr + 1));
	
    char msg[][3] = {"AB", "gh", "er"}; 
    char (*ptr2)[3];  
    
    ptr2 = &msg[0];
    printf("\n%p %p", msg, ptr2);
    printf("\n 2 %c %c", (*ptr2)[0], (*ptr2)[1]);

    return 0;
}

