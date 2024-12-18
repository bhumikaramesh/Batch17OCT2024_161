#include <stdio.h>
#include <stdlib.h>

int main() {
    int arr[][3] = {1, 2, 3, 4, 5, 6};
    printf("\n  1: %d %d", arr[1][0], arr[0][2]);
    int *ptr = arr[1];
    printf("\n 2:  %d %d %d", *(ptr+0), *(ptr+1), *(ptr+2));
    int *ptr2[3]; 
    ptr2[0] = &arr[0][0];
    ptr2[1] = &arr[0][1];
    ptr2[2] = &arr[0][2];
    printf("\n 3:  %d %d %d", *ptr2[0], *ptr2[1], *ptr2[2]);
    int (*ptr3)[2];
    ptr3 = arr[0];  
    printf("\n 4: %d %d %d", (*ptr3)[0], (*ptr3)[1], (*ptr3)[2]);

    ptr3++;  // Increment the pointer to point to the next row
    printf("\n 4: %d %d %d", (*ptr3)[0], (*ptr3)[1], (*ptr3)[2]);

    return 0;
}

