#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *line;
    int word_count;
} line_word_count_t;

int count_words(const char *line) {
    int count = 0;
    char *token;
    char *line_copy = strdup(line);
    token = strtok(line_copy, " ");
    while (token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    free(line_copy);
    return count;
}

void *thread_proc(void *arg) {
    line_word_count_t *data = (line_word_count_t *)arg;
    data->word_count = count_words(data->line);
    printf("Line: %s\n", data->line);
    printf("Word count: %d\n", data->word_count);
    return NULL;
}

pthread_t *createthreads(int num_threads) {
    return malloc(num_threads * sizeof(pthread_t));
}

void process_file(const char *filename, pthread_t *threads, int num_threads) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return;
    }

    char line[MAX_LINE_LENGTH];
    line_word_count_t *data = malloc(num_threads * sizeof(line_word_count_t));

    for (int i = 0; i < num_threads && fgets(line, sizeof(line), file); i++) {
        data[i].line = strdup(line); 
        pthread_create(&threads[i], NULL, thread_proc, &data[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < num_threads; i++) {
        free(data[i].line);
    }
    free(data);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];

    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return 1;
    }

    int num_lines = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        num_lines++;
    }
    fclose(file);

    pthread_t *threads = createthreads(num_lines);

    process_file(filename, threads, num_lines);

    free(threads);

    return 0;
}

