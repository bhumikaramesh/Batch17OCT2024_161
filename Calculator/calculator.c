#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
 
struct Stack
{
    float* array;
    int top;
    int capacity;
};
 
float customMod(float a, float b){
	return a-b*(int)(a/b);
}
struct Stack* createStack(int capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (float*)malloc(stack->capacity * sizeof(float));
    return stack;
}
 
void push(struct Stack* stack, float item) {
    stack->array[++stack->top] = item;
}
 
float pop(struct Stack* stack) {
    return stack->array[stack->top--];
}
 
float top(struct Stack* stack) {
    return stack->array[stack->top];
}
 
bool isEmpty(struct Stack* stack) {
    return stack->top == -1;
}
 
// Updated function to check if a character is a valid digit
bool isDigit(char c) {
    return (c >= '0' && c <= '9') || c == '.' || (c == '-' && isdigit(c)); // Fixed isdigit check
}
 
// Updated function to check if a character is a valid operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}
 
bool precedes(char prev, char curr) {
    if (prev == '(' || prev == '{' || prev == '[')
        return false;
    if ((prev == '*' || prev == '/') && (curr == '+' || curr == '-'))
        return false;
    return prev == '*' || prev == '/' || prev == '%' || curr == '+' || curr == '-';
}
 
void calc(struct Stack* nums, struct Stack* ops) {
    float b = pop(nums);
    float a = pop(nums);
    char op = (char)pop(ops);
 
    switch (op) {
        case '+':
            push(nums, a + b);
            break;
        case '-':
            push(nums, a - b);
            break;
        case '*':
            push(nums, a * b);
            break;
        case '/':
            push(nums, a / b);
            break;
        case '%':
            push(nums, customMod(a, b));
            break;
    }
}
 
float calculate(char* s) {
    struct Stack* nums = createStack(100);
    struct Stack* ops = createStack(100);
    bool hasPrevNum = false;
 
    for (int i = 0; s[i] != '\0'; ++i) {
        char c = s[i];
        if (isDigit(c)) {
            // Your existing code for processing digits
            // ...
            float num = (float)(c - '0');
            float decimal = 10.0;
 
            while (s[i + 1] != '\0' && (isDigit(s[i + 1]) || s[i + 1] == '.')) {
                if (s[i + 1] == '.') {
                    i++;  // skip the dot
                    while (s[i + 1] != '\0' && isDigit(s[i + 1])) {
                        num = num + (float)(s[++i] - '0') / decimal;
                        decimal *= 10.0;
                    }
                } else {
                    num = num * 10.0 + (float)(s[++i] - '0');
                }
            }
 
            push(nums, num);
            hasPrevNum = true;
        } else if (c == '(' || c == '{' || c == '[') {
            push(ops, c);
            hasPrevNum = false;
        } else if (c == ')' || c == '}' || c == ']') {
            while (top(ops) != '(' && top(ops) != '{' && top(ops) != '[')
                calc(nums, ops);
            pop(ops);  // Pop corresponding opening bracket.
        } else if (isOperator(c)) {
            if (!hasPrevNum)
                push(nums, 0.0);
            while (!isEmpty(ops) && precedes(top(ops), c))
                calc(nums, ops);
            push(ops, c);
        } else {
            printf("Invalid input. Exiting...\n");
            exit(1); // Exit the program with an error code for invalid input
        }
    }
 
    while (!isEmpty(ops))
        calc(nums, ops);
 
    float result = top(nums);
    free(nums->array);
    free(ops->array);
    free(nums);
    free(ops);
    return result;
}
 
int main() {
    char expression[100];
    printf("Input Expression: ");
    scanf("%[^\n]s",expression);
    float result = calculate(expression);
    printf("Result: %f\n", result);
 
    return 0;
}
