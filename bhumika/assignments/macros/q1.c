#include <stdio.h>

#define FIND_MIN(arr, size, min)       \
    do {                                \
        min = arr[0];                  \
        for (int i = 1; i < size; i++) { \
            if (arr[i] < min) {        \
                min = arr[i];          \
            }                           \
        }                               \
    } while (0)

int main() {
    int arr[] = {46, 51,5,2,87, 3, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    int min;

    FIND_MIN(arr, size, min);

    printf("The smallest number in the array is: %d\n", min);
    return 0;
}
