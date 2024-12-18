#include<stdio.h>

// We can avoid use of these using references
#define N 10
int n = 1;

void fun2();
//calculate the factorial of given number
int  fact(int n)
{
        int res = 1;
        unsigned int count = 0x01ffffff;
        unsigned int i = 0;
        if (n == 1)
        {
                        return n;
        }
        //this is just a delay loop added to increase execution time

        for (i = 0; i < count;i++)
        {
                        //testrun

        }
        res = n * fact(n-1);
}



// calls fact() for all values of n..1, get the cumulative sum of fact() results
int getall_fact_sum(int n)
{
    int res = 0;
    while (n > 1)
    {
        int factres = fact(n);
                res += factres;
                printf("\nF1: fact(%d):%d, tot:%d", n, factres, res);
        n--;
    }
    return res;
}


// Driver Program
int main(void)
{
    //int res = fact(5);
        int res = getall_fact_sum(5);
        printf("\n res:%d", res);
   // fun1();
    return 0;
}
