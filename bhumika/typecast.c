#include <stdio.h>
#include <stdbool.h>  // For using bool type

int main() {

    int i = 123;
    short s = 98;
    bool b = true;
    char c = 'Y';  // ASCII value of 'Y' is 89
    float d = 235.789;


    printf("b + c = %d\n", b + c);  // b is true (1), c is 'Y' (89), so 1 + 89 = 90

    printf("s * i = %d\n", s * i);  // 98 * 123 = 12054

    printf("c * d = %.2f\n", c * d);  // c is 'Y' (ASCII 89), 89 * 235.789 = 20945.401

    c = c + b;  // c = 89 (ASCII of 'Y') + 1 (true), so c becomes 90, which corresponds to 'Z'
    printf("c = c + b -> c = %c\n", c);  // 'Z'

    d = d + c;  // c is now 90 (ASCII of 'Z'), so d becomes 235.789 + 90 = 325.789
    printf("d = d + c -> d = %.2f\n", d);  // 325.79

    b = -d;  // -325.789 is a negative float, but in boolean, non-zero values are considered true
    printf("b = -d -> b = %d\n", b);  // Since -d is non-zero, b will be true (1)

    return 0;
}

