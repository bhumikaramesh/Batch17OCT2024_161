#include <stdio.h>

void myFunction() {
    // Display the file name, function name, and line number
    printf("File: %s\n", __FILE__);           // File name
    printf("Function: %s\n", __FUNCTION__);   // Function name
    printf("Line number: %d\n", __LINE__);    // Line number
}

int main() {
    // Display the file name, function name, and line number
    printf("File: %s\n", __FILE__);           // File name
    printf("Function: %s\n", __FUNCTION__);   // Function name
    printf("Line number: %d\n", __LINE__);    // Line number
    
    // Call the function
    myFunction();
    
    return 0;
}

