#include <stdio.h>
#include <stdlib.h>

long *solution(int array_count, int array[], int *result_count) {
    long *result = (long *)malloc(array_count * sizeof(long));
    if (result == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    int found;
    *result_count = 0;

    for (int i = 0; i < array_count; i++) {
        found = 0;
        
        for (int j = 0; j < *result_count; j++) {
            if (array[i] == result[j]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            result[*result_count] = array[i];
            (*result_count)++;
        }
    }

    return result; 
}

void printArray(long *array, int count) {
    for (int i=0;i<count;i++) {
        printf("%ld ", array[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the n value: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i<n; i++) {
        printf("Enter the values: ");
        scanf("%d", &arr[i]);
    }

    int result_count = 0;
    long *unique_values = solution(n, arr, &result_count);

    printf("Unique elements: ");
    printArray(unique_values, result_count);

    free(unique_values);

    return 0;
}

