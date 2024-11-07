Write a c program to print alphabet triangle.
Input: 5
Output:

     A
    ABA
   ABCBA
  ABCDCBA
 ABCDEDCBA
   
/*************************************************************************
*
*  FILE NAME    : assignment4.c
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





#include<stdio.h>
void main()
{
    int n=5,i,j;

    for(int i=1;i<=n;i++)
    {
        for(j=1;j<=n-i;j++)
        {
            printf(" ");
        }
        for(j=1;j<=i;j++)
        {
            printf("%c",(char)(j+64));
        }
        for(j=i-1;j>=1;j--)
        {
            printf("%c",(char)(j+64));
        }
        printf("\n");
    }
}