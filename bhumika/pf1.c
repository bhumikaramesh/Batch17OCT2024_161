#include <stdio.h>
#include <ctype.h> 
void readdisplay2()
{
    char ch, str[81];  
    int num;
    short s;
    float f;
    printf("Enter a character, an integer, a string (max 80 chars), a short number, and a float (separate by spaces): ");
    scanf(" %c %d %[^\n] %hd %f", &ch, &num, str, &s, &f);
    printf("You entered character: %c\n", ch);
    printf("You entered integer: %d\n", num);
    printf("You entered string: %s\n", str);
    printf("String in uppercase: ");
    for (int i = 0; str[i] != '\0'; i++) {
        putchar(toupper(str[i]));
    }
    printf("\n");
    printf("You entered short: %hd\n", s);
    printf("You entered float: %.f\n", f);
    printf("\nSize of char: %zu bytes\n", sizeof(ch));
    printf("Size of int: %zu bytes\n", sizeof(num));
    printf("Size of char array: %zu bytes\n", sizeof(str));
    printf("Size of short: %zu bytes\n", sizeof(s));
    printf("Size of float: %zu bytes\n", sizeof(f));
    printf("\nSize of data types (using sizeof):\n");
    printf("Size of char type: %zu bytes\n", sizeof(char));
    printf("Size of int type: %zu bytes\n", sizeof(int));
    printf("Size of short type: %zu bytes\n", sizeof(short));
    printf("Size of float type: %zu bytes\n", sizeof(float));
}

int main() {

    printf("Test Case 1:\n");
    readdisplay2();
    printf("\nTest Case 2:\n");
    readdisplay2();

    return 0;
}

