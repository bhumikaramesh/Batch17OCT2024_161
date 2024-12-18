#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *line;
    int word_count;
} thread_data_t;

int count_words(const char *line) {
    int count = 0;
    char *line_copy = strdup(line);
    char *token = strtok(line_copy, " ");
    while (token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    free(line_copy); 
    return count;
}

void *thread_proc(void *arg) {
    thread_data_t *data = (thread_data_t *)arg;
    data->word_count = count_words(data->line);
    printf("Line: '%s'\nWord count: %d\n", data->line, data->word_count);
    free(data->line); 
    free(data); 
    return NULL;
}

void create_and_process_threads(char *lines[], int num_lines) {
    pthread_t *threads = malloc(num_lines * sizeof(pthread_t));
    thread_data_t **data = malloc(num_lines * sizeof(thread_data_t *));
    
    for (int i = 0; i < num_lines; i++) {
        data[i] = malloc(sizeof(thread_data_t));
        data[i]->line = strdup(lines[i]); 
        pthread_create(&threads[i], NULL, thread_proc, data[i]);
    }

    for (int i = 0; i < num_lines; i++) {
        pthread_join(threads[i], NULL);
    }

    free(threads); 
    free(data);    
}

int main() {
    char *lines[] = {
        "This is a sample line",
        "Multithreading in C is fun",
        "Memory management is crucial"
    };

    create_and_process_threads(lines, 3);

    return 0;
}

