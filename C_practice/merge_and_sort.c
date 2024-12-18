#include<stdio.h>
int main(){
	int i,n1,n2;
	printf("Enter element in array one: ");
	scanf("%d",&n1);
	int arr1[n1];//array1
	printf("Enter array one element: ");
	for(i=0;i<n1;i++){
		scanf("%d",&arr1[i]);
	}
	printf("Enter element in array two: ");
	scanf("%d",&n2);
	int arr2[n2];//array2
	printf("Enter element in array two: ");
	for(i=0;i<n2;i++){
		scanf("%d",&arr2[i]);
	}
	int n3 = n1+n2;
	int arr3[n3];// merged array
	// appending array1 and array2 into array3
	for(i=0;i<n1;i++){
		arr3[i]=arr1[i]; 	
	}
	for(i=0;i<n2;i++){
		arr3[i+n1]=arr2[i];
	}
	//Applying sorting
	for(int j=0;j<n3-1;j++){
		for(i=0;i<n3-j-1;i++){
			if(arr3[i]>arr3[i+1]){
				int temp = arr3[i];
				arr3[i] = arr3[i+1];
				arr3[i+1] = temp;
			}	
		}
	}
	for(i=0;i<n3;i++){
		printf("%d ",arr3[i]);
	}
	return 0;

}
