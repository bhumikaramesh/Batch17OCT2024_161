Write a c program to print alphabet triangle.
Input: 5
Output:
     1
    121
   12321
  1234321
 123454321


/*************************************************************************
*
*  FILE NAME    : assignment3.c
*
*  DESCRIPTION  : Program to print alphabet traingle
*  DATE      NAME    
*  7-NOV-24  BHUMIKA   

**************************************************************************/

/*************************************************************************
*				HEADER FILES
*************************************************************************/
#include <stdio.h>

/*************************************************************************

/******************************************************************************
*
*       Function Name   : Main
*       Description     : Demonstration of nested for loops

*******************************************************************************/

#include <stdio.h>

int main() {
    int n = 5;  // Number of rows 
    
    for (int i = 1; i <= n; i++)
	 {
     
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }

        // Print increasing numbers from 1 to i
        for (int j = 1; j <= i; j++) {
            printf("%d", j);
        }

        // Print decreasing numbers from i-1 to 1
        for (int j = i - 1; j >= 1; j--) {
            printf("%d", j);
        }

        printf("\n");
    }

    return 0;
}
