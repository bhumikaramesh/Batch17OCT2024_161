#include <stdio.h>

// Function to count the number of 1's in the number (Hamming weight)
unsigned int countOnes(unsigned int num) {
    unsigned int count = 0;
    while (num) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

// Function to generate the even and odd parity bits for a 32-bit number
void generateParityBits(unsigned int num, unsigned int *evenParity, unsigned int *oddParity) {
    // Count the number of 1's in the number
    unsigned int onesCount = countOnes(num);

    // Even parity bit: 1 if the number of 1's is odd, 0 if even
    *evenParity = (onesCount % 2 == 0) ? 0 : 1;

    // Odd parity bit: 1 if the number of 1's is even, 0 if odd
    *oddParity = (onesCount % 2 == 0) ? 1 : 0;
}

int main() {
    unsigned int num;
    unsigned int evenParity, oddParity;

    // Read a 32-bit unsigned integer
    printf("Enter a 32-bit unsigned integer (in hex, e.g., 0xA5B3C7D1): ");
    scanf("%x", &num);

    // Generate the even and odd parity bits
    generateParityBits(num, &evenParity, &oddParity);

    // Display the results
    printf("Number: 0x%X\n", num);
    printf("Even Parity Bit: %u\n", evenParity);
    printf("Odd Parity Bit: %u\n", oddParity);

    return 0;
}

