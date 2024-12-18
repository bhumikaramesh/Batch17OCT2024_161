#include <stdio.h>
int add(int x, int y);
int sub(int x, int y);
int multiply(int x, int y);
int divide(int x, int y);

int main() 
{
    int (*operation)(int, int);
    char operator;
    int num1, num2, result;
    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operator);

    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);
    switch(operator) {
        case '+':
            operation = add;
            break;
        case '-':
            operation = sub;  
            break;
        case '*':
            operation = multiply; 
            break;
        case '/':
            operation = divide;  
            break;
        default:
            printf("Invalid operator!\n");
            return 1;  
    }
    result = operation(num1, num2);
    printf("Result: %d\n", result);

    return 0;
	}
int add(int x, int y) 
{
    return x + y;
}

int sub(int x, int y) 
{
    return x - y;
}

int multiply(int x, int y) 
{
    return x * y;
}

int divide(int x, int y) {
    if (y == 0) {
        printf("Error: Division by zero!\n");
        return 0; 
    }
    return x / y;
}

