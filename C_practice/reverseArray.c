#include<stdio.h>
int main(){
	int n; //no. of element
	printf("Enter no. of element: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter array element: \n");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	// printing array in forward order
	for(int i = 0;i<n;i++){
		printf("%d\n",arr[i]);
	}
	//printing array in reverse order
	for(int i=n-1;i>=0;i--){
		printf("%d\n",arr[i]);
	}
	return 0;
}
