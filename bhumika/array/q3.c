#include <stdio.h>
#include <string.h>
void sort(char arr[], int n);

int main() 
{
    char arr[] = "xaybz";
    sort(arr, sizeof(arr)/sizeof(arr[0])-1);
    printf("Sorted array: %s\n", arr);

    return 0;
}
t
void sort(char arr[], int n) {
    int i,j;
	char temp;
    for ( i = 0; i < n - 1; i++) {
        for ( j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

