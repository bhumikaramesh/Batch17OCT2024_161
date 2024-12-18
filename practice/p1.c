#include<stdio.h>
#include<stdlib.h>

void sortArr(long *a,int n)
{
	int i,j;
	long t;
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(a[i]<a[j])
			{
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}

	}
}
}
long *solution(array_count,array,&result_count)
{
	int maxSize=100;
	int idx=0;
	long *res=(long *)malloc(sizeof(long)*maxSize);
	sortArr(array,array_count);
	for(int i=0;i<array_count;i++)
		{
			if((i==0)||array[i]!=array[i+1])
			{
			res[idx++]=array[i];
			}
		}
	*result_count=idx;
	return res;
}
