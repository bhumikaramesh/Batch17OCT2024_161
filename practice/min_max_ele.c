#include<stdio.h>

void minMax(int a[],int len,int *min,int *max){
	*min, *max = a[0];
	for(int i=1;i<len;i++){
		if(a[i] < *min)
			*min = a[i];
		if(a[i] > *max)
			*max = a[i];
	}

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
        int min,max;
	minMax(arr,n,&min,&max);
	printf("%d %d",min ,max);
	return 0;

}













/*
int main(){
	int n;
	printf("Enter array size: ");
	scanf("%d",&n);
//	printf("%d",n);

	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int min,max;
	min = max = arr[0];

	for(int i=1;i<n;i++){
		if(arr[i]<min){
			min = arr[i];
		}
		if(arr[i]>max){
			max = arr[i];
		}
	}
	printf("%d %d",min,max);
}
*/
