#include <stdio.h>
#include <stdlib.h>

void func1(short mat[][3]);
void func2(short (*ptr)[3]);
void func3(short *);
void func4(short **);
void func5(short *ptr[3]);

/**************************************************************************
*
* FUNCTION NAME: main
*
* DESCRIPTION: main function for 2D array - function program
*
* RETURNS: Nothing
**************************************************************************/
int main()
{
    short mat[3][3],i,j;

    for(i = 0 ; i < 3 ; i++)
        for(j = 0 ; j < 3 ; j++)
        {
            mat[i][j] = i*10 + j;
        }

    printf("Initialized data to: ");
    for(i = 0 ; i < 3 ; i++)
    {
        printf("\n");
        for(j = 0 ; j < 3 ; j++)
        {
            printf("%5.2d", mat[i][j]);
        }
    }
    printf("\n");

    func1(mat);
    func2(mat);
    func3((short *)mat);
    func4((short **)mat);
    func5((short **)mat);
    
    return 0;
}

/* 
Method #1 (No tricks, just an array with empty first dimension)
==============================================================
You don't have to specify the first dimension! 
*/
void func1(short mat[][3])   
{
    register short i, j;

    printf("Declare as matrix, explicitly specify second dimension: ");
    for(i = 0 ; i < 3 ; i++)
    {
        printf("\n");
        for(j = 0 ; j < 3 ; j++)
        {
            printf("%5.2d", mat[i][j]);  // Display the element
        }
    }
    printf("\n");
}

/* Method #2 (Pointer to array, second dimension is explicitly specified)
======================================================================
*/
void func2(short (*mat)[3])
{
    register short i, j;

    printf("Declare as pointer to column, explicitly specify 2nd dim: ");
    for(i = 0 ; i < 3 ; i++)
    {
        printf("\n");
        for(j = 0 ; j < 3 ; j++)
        {
            printf("%5.2d", mat[i][j]);  // Display the element
        }
    }
    printf("\n");
}

/*
Method #3 (Using a single pointer, the array is "flattened")
===========================================================
With this method you can create general-purpose routines.
The dimensions don't appear in any declaration, so you can add them to the formal argument list. 
*/
void func3(short *mat)  
{
    register short i, j;

    printf("Declare as single-pointer, manual offset computation: ");
    for(i = 0 ; i < 3 ; i++)
    {
        printf("\n");
        for(j = 0 ; j < 3 ; j++)
        {
            // Accessing the element using pointer arithmetic
            printf("%5.2d", *(mat + i*3 + j));  // Display the element using manual offset
        }
    }
    printf("\n");
}

/*
Method #4 (Double pointer, using an auxiliary array of pointers)
================================================================
*/
void func4(short **mat)
{
    short i, j, *index[3];

    // Initialize the index array to point to each row of mat
    for(i = 0; i < 3; i++)
    {
        index[i] = mat[i];
    }

    printf("Declare as double-pointer, use auxiliary pointer array: ");
    for(i = 0; i < 3; i++)
    {
        printf("\n");
        for(j = 0; j < 3; j++)
        {
            printf("%5.2d", *(index[i] + j));  // Access the element using the index array
        }
    }
    printf("\n");
}

/*
Method #5 (Single pointer, using an auxiliary array of pointers)
================================================================
*/
void func5(short *mat[3])
{
    short i, j, *index[3];
    
    // Initialize the index array to point to each row of mat
    for(i = 0; i < 3; i++)
    {
        index[i] = mat[i];
    }

    printf("Declare as single-pointer, use auxiliary pointer array: ");
    for(i = 0; i < 3; i++)
    {
        printf("\n");
        for(j = 0; j < 3; j++)
        {
            printf("%5.2d", *(index[i] + j)); 
        }
    }
    printf("\n");
}

