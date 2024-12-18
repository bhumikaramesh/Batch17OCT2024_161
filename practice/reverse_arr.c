#include<stdio.h>
#define N 5
int main(){
	int a[N],*p;
	printf("Enter %d the array:",N);
	for(p=a;p<=a+N-1;p++){
		scanf("%d",p);
	}
	printf("Reverse array: ");
	for(p=a+N-1;p>=a;p--){
		printf("%d",*p);
	}
	
	return 0;







/*	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}

	
	for(int i=0;i<n/2;i++){
		int temp = arr[i];
		arr[i] = arr[n-1-i];
		arr[n-1-i] = temp;
	}

	for(int i=0;i<n;i++){
		printf("%d",arr[i]);
	}
	*/
}
