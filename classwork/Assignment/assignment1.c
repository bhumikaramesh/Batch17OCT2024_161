#include <stdio.h>
#include<stdbool.h>
bool prime(int num)
{
    int i;
    if (num<=1) 
    {
        return false;
    }
    for (int i=2;i*i<=num;i++) 
    {
        if (num%i==0)
        {
            return false;
        }
    }
    return true;
}

void primecheck(int n)
{
    int count;
    for(int i=2;i<=n/2;i++)
    if (prime(i)&&prime(n-i))
    {
            printf("%d=%d+%d\n",n,i,n-i);
            count++;
        }
    
    if (count==0)
    {
        printf("NoofWays = -1\n");
    } else 
    {
        printf("NoofWays = %d\n", count);
    }
}

int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n<=1) {
        printf("NoofWays = -1\n");
    } else {
        primecheck(n);
    }

    return 0;
}
