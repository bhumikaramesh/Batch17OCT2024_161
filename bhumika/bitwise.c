#include <stdio.h>

unsigned char swapBits(unsigned char num) {
    // Mask for odd and even bits
    unsigned char evenBits = num & 0xAA;  // Mask for even positions (D0, D2, D4, D6)
    unsigned char oddBits  = num & 0x55;  // Mask for odd positions (D1, D3, D5, D7)

    // Right shift even bits and left shift odd bits
    evenBits >>= 1;
    oddBits  <<= 1;

    // Combine the shifted bits
    return evenBits | oddBits;
}

int main() {
    unsigned char num;

    // Read an 8-bit unsigned integer (Hex input)
    printf("Enter an 8-bit unsigned integer (in hex: ");
    scanf("%hhx", &num);

   
    unsigned char result = swapBits(num);

   
    printf("Original number: 0x%X\n", num);
    printf("After swapping adjacent bits: 0x%X\n", result);

    return 0;
}

