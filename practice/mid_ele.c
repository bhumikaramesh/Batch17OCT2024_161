#include<stdio.h>

int *findMid(int arr[],int len){
	return &arr[len/2];
}

int main(){
        int n;
        printf("Enter array size: ");
        scanf("%d",&n);
//      printf("%d",n);

        int arr[n];
        for(int i=0;i<n;i++){
                scanf("%d",&arr[i]);
        }
//	int len = sizeof(arr)/sizeof(arr[0]);
	int *mid = findMid(arr,n);


//	int mid = len/2;
	printf("%d", *mid);

	return 0;
}
