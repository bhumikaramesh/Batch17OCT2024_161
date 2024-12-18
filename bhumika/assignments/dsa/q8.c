#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <ctype.h>

int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

void *sort_words(void *arg) {
    char *line = (char *)arg;
    char *token;
    char *words[100];
    int count = 0;

    token = strtok(line, " ");
    while (token != NULL) {
        words[count++] = token;
        token = strtok(NULL, " ");
    }

    qsort(words, count, sizeof(char *), compare);

    printf("Sorted line: ");
    for (int i = 0; i < count; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Please provide 3 lines as arguments.\n");
        return 1;
    }

    pthread_t threads[3];

    for (int i = 1; i <= 3; i++) {
        char *line = strdup(argv[i]); 
        if (pthread_create(&threads[i - 1], NULL, sort_words, line)) {
            fprintf(stderr, "Error creating thread\n");
            return 1;
        }
    }

    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

