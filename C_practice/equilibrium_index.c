#include<stdio.h>
int equilibrium(int a[],int n);

		
int main(){
	int n;
	printf("Enter array size: ");
	scanf("%d", &n);
	int i;
	int arr[n];
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	/*
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
`	 */	
	int index = equilibrium(arr,n);
	printf("%d: ",index);
	return 0;
}
int equilibrium(int arr[],int n){
	for(int i=0;i<n;i++){
		int leftsum = 0;
		for(int j=0;j<i;j++)
			leftsum += arr[j];
		int rightsum = 0;
		for(int j=i+1;j<n;j++)
			rightsum += arr[j];
		if(leftsum == rightsum)
			return i;
		
	
	}
	return -1;
	
}
