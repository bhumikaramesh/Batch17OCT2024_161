#include <stdio.h>

#define MAX 100
void init(int arr[], int N, int start);
void update(int arr[], int N);
void display(int arr[], int N);

int main() {
    int arr[MAX]; 
    int N, start;
    printf("Enter the number of elements (N): ");
    scanf("%d", &N);
    
    printf("Enter the starting value: ");
    scanf("%d", &start);
   
    init(arr, N, start);

    printf("Array after initialization:\n");
    display(arr, N);
    update(arr, N);

    printf("Array after update:\n");
    display(arr, N);
    
    return 0;
}
void init(int arr[], int N, int start) {
    for (int i = 0; i < N; i++) {
        arr[i] = start + i;
    }
}

void update(int arr[], int N) {
    for (int i = 0; i < N; i++) {
        arr[i] = arr[i] + 1; 
  }
  }
void display(int arr[], int N) {
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

