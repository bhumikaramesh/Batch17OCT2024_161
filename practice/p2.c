#include<stdio.h>
#include<stdlib.h>

// Function to sort the array in descending order
void sortArr(long *a, int n) {
    int i, j;
    long t;
    for(i = 0; i < n; i++) {
        for(j = i; j < n; j++) {  // Fixed the inner loop to start from i + 1
            if(a[i] > a[j]) {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}

// Function to find unique elements in the array
long *solution(int array_count, long *array, int *result_count) {
    int maxSize = 100;  // Maximum size for result array
    int idx = 0;        // Index for result array
    long *res = (long *)malloc(sizeof(long) * maxSize);  // Allocate memory for result array

    sortArr(array, array_count);  // Sort the input array in descending order

    for(int i = 0; i < array_count; i++) {
        if(i == array_count - 1 || array[i] != array[i + 1]) {  // Ensure not going out of bounds
            res[idx++] = array[i];  // Add unique element to result array
        }
    }

    *result_count = idx;  // Set the result count
    return res;  // Return the result array with unique elements
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    long *arr = (long *)malloc(sizeof(long) * n);  // Dynamically allocate memory for input array

    // Read the input array values
    for(int i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%ld", &arr[i]);
    }

    int result_count = 0;
    long *unique_values = solution(n, arr, &result_count);  // Call the solution function

    // Print the unique sorted elements
    printf("Unique elements: ");
    for(int i = 0; i < result_count; i++) {
        printf("%ld ", unique_values[i]);
    }
    printf("\n");

    // Free dynamically allocated memory
    free(arr);
    free(unique_values);

    return 0;
}

