#include<stdio.h>

int main(){
	int arr[] = {1,2,3,4,5};
	int len = sizeof(arr)/sizeof(arr[0]);
	printf("%d",len);
	return 0;

}
