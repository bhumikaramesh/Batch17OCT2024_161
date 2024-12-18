
#include <stdio.h>

void swap(int* arr, int i, int j) {
    int temp;
	temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

void bubbleSort(int arr[], int n) {
	int i,j;
    for ( i=0;i<n-1;i++)
	{
        for ( j=0;j<n-i-1;j++) {

            if (arr[j]>arr[j + 1])
                swap(arr,j,j+1);
        }
    }
}

int main() {
    int arr[]={ 5,60, 75, 44 };
	int i;
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,n);

    for ( i=0; i<n; i++)
        printf("%d\n",arr[i]);

    return 0;
}
