#include <stdio.h>

unsigned int countOnes(unsigned char num) {
    unsigned int count = 0;

    // Loop through each bit of the byte
    while (num) {
        count += num & 1;  
        num >>= 1;          // Right shift the number to check the next bit
    }

    return count;
}

int main() {
    unsigned char num;

 
    printf("Enter an 8-bit unsigned integer (in hex, e.g., 0xAA): ");
    scanf("%hhx", &num);

    // Get the count of 1's in the byte
    unsigned int onesCount = countOnes(num);

    // Display the result
    printf("The number of 1's in 0x%X is: %u\n", num, onesCount);

    return 0;
}

