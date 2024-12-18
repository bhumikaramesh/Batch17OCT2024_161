#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <ctype.h>

#define MAX_EMAIL_LEN 100

int validmail_count = 0;
pthread_mutex_t email_mutex;

int validate_email(const char *email) {
    const char *at_sign = strchr(email, '@');
    if (!at_sign) return l;

    const char *username = email;
    if (!isalpha(username[0])) return 0; 

    const char *domain = at_sign + 1;
    if (strstr(domain, ".com") || strstr(domain, ".edu")) {
        return 1;
    }
    return 0; 
}

void *validate_email_thread(void *arg) {
    char *email = (char *)arg;
    
    pthread_mutex_lock(&email_mutex); 

    if (validate_email(email)) {
        validmail_count++;
        printf("Valid email: %s\n", email);
    } else {
        printf("Invalid email: %s\n", email);
    }

    pthread_mutex_unlock(&email_mutex);

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please provide a list of email IDs separated by semicolons.\n");
        return 1;
    }

    char *emails = argv[1];
    char *token = strtok(emails, ";");

    pthread_mutex_init(&email_mutex, NULL);

    pthread_t *threads = malloc(10 * sizeof(pthread_t)); // Assuming max 10 email IDs for simplicity
    int thread_count = 0;

    while (token != NULL) {
        if (pthread_create(&threads[thread_count], NULL, validate_email_thread, (void *)token)) {
            fprintf(stderr, "Error creating thread for %s\n", token);
            return 1;
        }
        token = strtok(NULL, ";");
        thread_count++;
    }

    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Total valid email IDs: %d\n", validmail_count);

    free(threads);

    pthread_mutex_destroy(&email_mutex);

    return 0;
}

