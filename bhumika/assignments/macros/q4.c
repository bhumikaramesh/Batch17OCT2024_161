#include <stdio.h>

// Uncomment the following line to define CUST_PRINT
 #define CUST_PRINT

#ifdef CUST_PRINT
    #define MYPRINT(x) printf(x)  // MYPRINT will be defined as printf when CUST_PRINT is defined
#else
    #define MYPRINT(x)  // MYPRINT will do nothing if CUST_PRINT is not defined
#endif

int main() {
    MYPRINT("Hello World\n"); // This will print "Hello World" only if CUST_PRINT is defined
    printf("Test\n"); // This will always print "Test"

    return 0;
}

