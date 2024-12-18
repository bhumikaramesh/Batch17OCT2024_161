#include <stdio.h>

int main()
{
    int i = 10;
    int j = 3;
    
    // Perform calculations
    float f1 = i / j;                // Integer division
    float f2 = (float) i / j;        // Floating-point division (cast i to float)
    float f3 = (float) (i / j);      // Integer division first, then cast to float
    
    // Print the results with appropriate formatting
    printf("f1 = %.6f\n", f1);  // Display f1 (integer division result as float)
    printf("f2 = %.6f\n", f2);  // Display f2 (floating-point division result)
    printf("f3 = %.6f\n", f3);  // Display f3 (integer division then cast to float)
    
    return 0;
}



