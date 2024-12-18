#include<stdio.h>
int main()
{
	int i,N,sum;
	printf("enter the value of N:");
	scanf("%d",&N);
	sum=0;
	for(int i=1;i<=N;i++)
		sum=sum+i;
		printf("sum of the seriesis %d",sum);
		return 0;
		}
