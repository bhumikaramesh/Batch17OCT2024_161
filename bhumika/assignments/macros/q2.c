#include <stdio.h>
#define MYPROD(x) ((x) * (x))

int main() {
    
    int output1 = MYPROD(2 + 1); // Should give 9
    int output2 = MYPROD(6 + 1); // Should give 49

    // Display the results
    printf("Result of MYPROD(2 + 1): %d\n", output1);
    printf("Result of MYPROD(6 + 1): %d\n", output2);

    return 0;
}

