#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <ctype.h>

#define MAX_STR_LEN 100

int is_palindrome = 0;
int not_palindrome = 0;

pthread_mutex_t mutex;

int is_palindromic(const char *str) {
    int len = strlen(str);
    int left = 0;
    int right = len - 1;

    while (left < right) {
        if (tolower(str[left]) != tolower(str[right])) {
            return 0; 
        }
        left++;
        right--;
    }
    return 1; 
}

void *check_palindrome(void *arg) {
    char *input = (char *)arg;
    int is_palindrome_check = is_palindromic(input);
    
    pthread_mutex_lock(&mutex); 

    if (is_palindrome_check) {
        is_palindrome++;
        printf("%s is a palindrome\n", input);
    } else {
        not_palindrome++;
        printf("%s is not a palindrome\n", input);
    }

    pthread_mutex_unlock(&mutex); 

    return (void *)input;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please provide at least one string argument.\n");
        return 1;
    }

    pthread_mutex_init(&mutex, NULL);

    pthread_t *threads = malloc((argc - 1) * sizeof(pthread_t));
    void *status;

    for (int i = 1; i < argc; i++) {
        if (pthread_create(&threads[i - 1], NULL, check_palindrome, (void *)argv[i])) {
            fprintf(stderr, "Error creating thread for %s\n", argv[i]);
            return 1;
        }
    }

    for (int i = 0; i < argc - 1; i++) {
        pthread_join(threads[i], &status);
        if (status != NULL) {
            printf("Returned by thread: %s\n", (char *)status);
        }
    }

    printf("Total palindromes: %d\n", is_palindrome);
    printf("Total non-palindromes: %d\n", not_palindrome);

    free(threads);

    pthread_mutex_destroy(&mutex);

    return 0;
}

