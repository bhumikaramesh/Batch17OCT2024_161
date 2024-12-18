#include <stdio.h>

int max_depth = 0;
int current_depth = 0;

long long factorial(int n) 
{
    current_depth++;
    if (current_depth > max_depth) {
        max_depth = current_depth;
    }
    if (n <= 1) {
        current_depth;
        return 1;
    }
    long long result = n * factorial(n - 1);
    current_depth--;
    
    return result;
}

int main() 
{
    int n;
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &n);
    long long fact = factorial(n);
    printf("Factorial of %d is %lld\n", n, fact);
    printf("Maximum stack depth during recursion: %d\n", max_depth);

    return 0;
}

