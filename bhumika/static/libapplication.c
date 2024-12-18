#include <stdio.h>
#include "cal_utility.h"  // Include the header to access the functions

int main() {
    int a = 10, b = 5;
    
    // Calling add function from cal_utility.c
    int sum = add(a, b);
    printf("Sum: %d\n", sum);

    // Calling multiply function from cal_utility.c
    int product = multiply(a, b);
    printf("Product: %d\n", product);

    return 0;
}

