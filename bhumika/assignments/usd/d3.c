#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **allocate_array_memory(char **ptr, int n) {
    ptr = (char **)malloc(n * sizeof(char *));
    if (ptr == NULL) {
        printf("Memory allocation failed for array of strings.\n");
        exit(1);
    }
    return ptr;
}

char *allocate_string_memory(char *string) {
    string = (char *)malloc(80 * sizeof(char));
    if (string == NULL) {
        printf("Memory allocation failed for string.\n");
        exit(1);
    }
    return string;
}

void display(char **arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("String %d: %s\n", i + 1, arr[i]);
    }
}

void free_array_memory(char **ptr, int n) {
    for (int i = 0; i < n; i++) {
        free(ptr[i]);
    }
    free(ptr);  
}

void free_string_memory(char *ptr) {
    free(ptr);
}

int main() {
    int n;
    printf("Enter the maximum number of strings to input: ");
    scanf("%d", &n);
    getchar(); 

    char **arr = allocate_array_memory(NULL, n);

    int i = 0;
    char *str = NULL;

    while (i < n) {
        str = allocate_string_memory(str);

        printf("Enter string %d: ", i + 1);
        fgets(str, 80, stdin);
        str[strcspn(str, "\n")] = '\0'; 

        if (strcmp(str, "end") == 0 || strcmp(str, "END") == 0) {
            free_string_memory(str);
            break;
        }

        arr[i] = str;
        i++;
    }

    printf("\nStored strings:\n");
    display(arr, i);

    free_array_memory(arr, i);

    return 0;
}

