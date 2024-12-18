#include<stdio.h>
int main(){
	int i,n;

	printf("Enter no. of element: ");
	scanf("%d",&n);
	int arr[n];	
	printf("Enter array element: ");
	for(i=0;i<n-1;i++){
		scanf("%d",&arr[i]);
	}
	int sum =0;
	for(i=0;i<n-1;i++){
		sum += arr[i];
	}
	int nsum = n*(n+1)/2;
	int missing_no = nsum - sum;
	printf("Missing no. : %d ",missing_no );
	return 0;
}
