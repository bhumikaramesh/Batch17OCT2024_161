#include <stdio.h>

void read_display() {
    char ch;
    int num;
    char str[81]; 
    short s;
    float f;
    printf("Enter a character: ");
    scanf(" %c", &ch); 
    printf("The entered character: %c\n", ch);

    printf("Enter an integer: ");
    scanf("%d", &num);
    printf("The entered integer: %d\n", num);
    printf("Enter a string (max 80 characters): ");
    scanf(" %[^\n]%*c", str);
    printf("The entered string: %s\n", str);
    printf("Enter a short number: ");
    scanf("%hd", &s);
    printf("The  entered short: %hd\n", s);
    printf("Enter a float number: ");
    scanf("%f", &f);
    printf("The entered float: %.4f\n", f);
}

int main() 
{
    printf("Test Case 1:\n");
    read_display();  
    printf("\nTest Case 2:\n");
    read_display();

    return 0;
}

