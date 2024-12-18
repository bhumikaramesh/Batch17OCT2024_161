#include <stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
float add(float a, float b) {
  printf("\n%s\n%s,arr
}

float subtract(float a, float b) {
    return a - b;
}

float multiply(float a, float b) {
    return a * b;
}

float divide(float a, float b) {
    if (b == 0) {
        printf("Error! Division by zero.\n");
        return -1; // Return -1 to indicate error
    }
    return a / b;
}

