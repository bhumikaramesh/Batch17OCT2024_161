#include <stdio.h>
int add(int x, int y);
int sub(int x, int y);
int multiply(int x, int y);
int divide(int x, int y);
int invokefunc(int (*func)(int, int), int val1);
int (*getaddr(char mychar))(int, int);  

int main() {
   
    int (*operation[4])(int, int) = {add, sub, multiply, divide};
    
    char operator;
    int num1, num2, result;
    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operator);  
    printf("Enter the second integer: ");
    scanf("%d", &num2);
    int (*func)(int, int) = getaddr(operator);
    if (func != NULL) {
        result = invokefunc(func, 10);  
        printf("Result: %d\n", result);
    } else {
        printf("Invalid operator!\n");
    }
    printf("Enter operator again to invoke from function pointer array (+, -, *, /): ");
    scanf(" %c", &operator);  

    switch(operator) {
        case '+':
            result = operation[0](10, num2); 
            break;
        case '-':
            result = operation[1](10, num2); 
            break;
        case '*':
            result = operation[2](10, num2); 
            break;
        case '/':
            result = operation[3](10, num2);  
            break;
        default:
            printf("Invalid operator!\n");
            return 1;
    }
    printf("Result from function pointer array: %d\n", result);

    return 0;
}

int add(int x, int y) {
    return x + y;
}

int sub(int x, int y) {
    return x - y;
}

int multiply(int x, int y) {
    return x * y;
}

int divide(int x, int y) {
    if (y == 0) {
        printf("Error: Division by zero!\n");
        return 0;  
    }
    return x / y;
}
int (*getaddr(char mychar))(int, int) {
    switch(mychar) {
        case '+':
            return add;
        case '-':
            return sub;
        case '*':
            return multiply;
        case '/':
            return divide;
        default:
            return NULL; 
    }
}

int invokefunc(int (*func)(int, int), int val1) {
    int val2;
    printf("Enter the second integer for the function: ");
    scanf("%d", &val2);
    
    return func(val1, val2);  
}

