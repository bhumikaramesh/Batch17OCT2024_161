#include <stdio.h>
int factorial1(int n, int accumulator) 
{
    if (n == 0) {
        return accumulator;
    } else {
        return factorial1(n - 1, n * accumulator);
    }
}

int factorial(int n)
{
    return factorial1(n, 1); 
}

int main()
{
    int num = 5;
    printf("Factorial of %d is %d\n", num, factorial(num)); 
    return 0;
}
