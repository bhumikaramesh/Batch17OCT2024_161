#include<stdio.h>

void swap(int *arr,int i,int j)
{
	int temp;
	temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}

void bubblesort(int arr[],int n)
{
	int i,j;
	for(i=0;i<=n-1;i++)
{
	for(j=0;j<-n-i-1;j++)
	{
		if(arr[j]>arr[j+1])
			swap(arr,j,j+1);
	}
}
}
int main() {
	int arr[] = { 6, 0, 3, 5 };
	int n = sizeof(arr)/sizeof(arr[0]);
 	bubblesort(arr, n);
 		for (int i = 0; i < n; i++)
  			printf("%d ", arr[i]);
  	 return 0;
}

	