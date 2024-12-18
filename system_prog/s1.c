#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

extern float add(float a, float b);
extern float subtract(float a, float b);
extern float multiply(float a, float b);
extern float divide(float a, float b);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <operation> <num1> <num2>\n", argv[0]);
        printf("Operations: add, subtract, multiply, divide\n");
        return 1;
    }

    char *operation = argv[1];
    float num1 = atof(argv[2]);
    float num2 = atof(argv[3]);

    pid_t pid = fork(); // Create a child process

    if (pid < 0) {
        // Fork failed
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        float result = 0;
        if (strcmp(operation, "+") == 0) {
            result = add(num1, num2);
        } 
        else if (strcmp(operation, "-") == 0) {
            result = subtract(num1, num2);
        } 
        else if (strcmp(operation, "*") == 0) {
            result = multiply(num1, num2);
        } 
        else if (strcmp(operation, "/") == 0) {
            result = divide(num1, num2);
            if (result == -1) {
                exit(1); // Exit if division by zero
            }
        } 
        else {
            printf("Invalid operation. Please choose from 'add', 'subtract', 'multiply', 'divide'.\n");
            exit(1);
        }

        // Print the result from the child process
        printf("Result: %.2f\n", result);
        exit(0); // Child process exits
    } else {
        // Parent process waits for the child to complete
        wait(NULL); // Wait for child process to finish
    }

    return 0;
}


