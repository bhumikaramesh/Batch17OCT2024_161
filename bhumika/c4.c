#include <stdio.h>

#define SORT_CHAR_ARRAY(arr, n) {               \
    for (int i = 0; i < (n) - 1; i++) {         \
        for (int j = 0; j < (n) - i - 1; j++) { \
            if ((arr)[j] > (arr)[j + 1]) {      \
                char temp = (arr)[j];           \
                (arr)[j] = (arr)[j + 1];       \
                (arr)[j + 1] = temp;           \
            }                                   \
        }                                       \
    }                                           \
}

int main() {
    char name[] = "CDEBAF";
    int n = sizeof(name) / sizeof(name[0]) - 1;  // exclude null terminator

    printf("Original array: %s\n", name);

    // Call the macro to sort the array
    SORT_CHAR_ARRAY(name, n);

    // Print the sorted array
    printf("Sorted array: %s\n", name);

    return 0;
}

