#include<stdio.h>

int gcd(int a,int b)
{
	int temp;
	while(b!=0)
	{
		temp=b;
		b=a%b;
		a=temp;
	}
	return a;
}
int main()
{
	int n,i;
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}

	if(n==1)
	{
		printf("%d\n",arr[0]);
		return 0;
	}

	int prefixGCD[n],suffixGCD[n];

	prefixGCD[n],suffixGCD[n]
