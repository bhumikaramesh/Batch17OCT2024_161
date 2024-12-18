
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
 
// Function declarations
int addsub();
int muldiv();
int term();
 
char input[101]; // Declare character array to store user input
int pos = 0;    // Initialize a global variable to keep track of the position in the input string
 
// Function to check if a character is an operator
int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}
 
// Function to parse and evaluate a term (number or expression inside parentheses)
int term() {
    int n = 0;
 
    // Check if the current character is an opening parenthesis
    if (input[pos] == '(') {
        pos++; // Move to the next character
        n = addsub(); // Evaluate the expression inside the parentheses
 
        // Check if the next character is a closing parenthesis
        if (input[pos] == ')') {
            pos++; // Move to the next character (closing parenthesis)
            return n; // Return the evaluated result
        }
    } else {
        // Check if the current character is a digit
        if (!isdigit(input[pos])) {
            printf("Invalid expression. Exiting...\n");
            exit(1); // Exit the program with an error code
        }
 
        // If the current character is a digit, parse the number
        while (isdigit(input[pos])) {
            n = n * 10 + (input[pos] - '0'); // Convert characters to integer and build the number
            pos++; // Move to the next character
        }
    }
 
    // Check if the current character is an operator or invalid
    if (!isdigit(input[pos]) && !isOperator(input[pos])) {
        printf("Invalid expression. Exiting...\n");
        exit(1); // Exit the program with an error code
    }
 
    return n; // Return the parsed number
}
 
// Function to handle multiplication and division operations
int muldiv() {
    int first, second;
 
    first = term(); // Evaluate the first term
 
    for (;;) {
        if (input[pos] == '*') {
            pos++; // Move to the next character (operator)
            second = term(); // Evaluate the second term
            first *= second; // Perform multiplication
        } else if (input[pos] == '/') {
            pos++; // Move to the next character (operator)
            second = term(); // Evaluate the second term
            if (second == 0) {
                printf("Division by zero. Exiting...\n");
                exit(1); // Exit the program with an error code
            }
            first /= second; // Perform division
        } else {
            return first; // If no more operators, return the result
        }
    }
}
 
// Function to handle addition and subtraction operations
int addsub() {
    int first, second;
 
    first = muldiv(); // Evaluate the first term
 
    for (;;) {
        if (input[pos] == '+') {
            pos++; // Move to the next character (operator)
            second = muldiv(); // Evaluate the second term
            first += second; // Perform addition
        } else if (input[pos] == '-') {
            pos++; // Move to the next character (operator)
            second = muldiv(); // Evaluate the second term
            first -= second; // Perform subtraction
        } else {
            return first; // If no more operators, return the result
        }
    }
}
 
int main() {
    printf("Input an expression using +, -, *, / operators:\n");
    scanf("%s", input); // Read the user input as a string
 
    // Check if the first character is a digit
    if (!isdigit(input[0])) {
        printf("Invalid expression. Exiting...\n");
        return 1; // Exit the program with an error code
    }
 
    int result = addsub(); // Evaluate the expression
    printf("Result: %d\n", result);
 
    return 0; // Indicate successful execution and return 0 to the operating system
}
