A4. rotate array every kth element

1 2 3 4 5 6 7 8 9

k= 3

3 2 1 6 5 4 9 8 7


/*************************************************************************
*
*  FILE NAME    : assignment2.c
*
*  DESCRIPTION  : 

*
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
*       Function Name   : reverse,rotate1,rotate2,main
*       Description     : Demonstration of arrays and functions

*******************************************************************************/



#include <stdio.h>

void reverse(int arr[],int start,int end)
{
    while(start < end)
    {
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
        
    }
}

void rotate1(int arr[],int n,int k)
{
    for(int i=0;i<n;i+=k)
    {
        int end = (i+k-1<n)?(i+k-1):(n-1);
        reverse(arr,i,end);
    }
}
void rotate2(int arr[],int n)
{
    for(int i=0;i<n;n++)
    {
    printf("%d",arr[i]);
    }
    printf("\n");
}
    int main()
    {
        int arr[]={1,2,3,4,5,6,7,8,9};
        int n=sizeof(arr)/sizeof(arr[0]);
        int k=3;
        printf("original array");
        rotate2(arr,n);
        rotate1(arr,n,k);
        printf("after rotating");
        rotate2(arr,n);
        return 0;
    }
