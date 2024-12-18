#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

typedef struct {
    unsigned long long large_serial_number;
    const char *my_name;
    pthread_t caller_thread;
} fun_thread_args_t;

#define NUM_LOOPS 5u

static void* _fun_thread_run(void *arg) {
    fun_thread_args_t *thread_args = (fun_thread_args_t *)arg;

    unsigned int counter = 0;
    bool done = false;

    char *username = malloc(100 * sizeof(char)); 
    if (username == NULL) {
        perror("Failed to allocate memory for username");
        return NULL;
    }

    printf("Thread %s asking for your username: ", thread_args->my_name);
    fgets(username, 100, stdin);
    username[strcspn(username, "\n")] = '\0'; 

    while (!done) {
        counter++;
        printf("My name is: '%s', my number is: %llX, loop count: %u\n",
               thread_args->my_name,
               thread_args->large_serial_number,
               counter);

        if (counter >= NUM_LOOPS) {
            printf("'%s' is sooooo done.\n", thread_args->my_name);
            done = true;
        } else {
            sleep(1u);
        }
    }

    printf("Thread %s completed, username entered: %s\n", thread_args->my_name, username);

    free(username);

    free(arg);

    return NULL;
}

static pthread_t _launch_fun_thread(unsigned long long serial_number, const char *name) {
    pthread_t thread;
    fun_thread_args_t *args = calloc(1, sizeof(*args));

    if (args == NULL) {
        perror("Failed to allocate memory for thread arguments");
        return thread;
    }

    args->caller_thread = pthread_self(); 
    args->large_serial_number = serial_number;
    args->my_name = name;

    int rc = pthread_create(&thread, NULL, &_fun_thread_run, args);
    if (rc != 0) {
        perror("Failed to create thread");
        free(args);
    }

    return thread;
}

int main(void) {
    puts("The fun we are having!");

    pthread_t fun_thread1;
    pthread_t fun_thread2;

    printf("Parent thread ID: %lu\n", pthread_self());
    fun_thread1 = _launch_fun_thread(0xABCDEF12345678ULL, "super FUN thread 1");

    usleep(500UL * 1000UL);
    fun_thread2 = _launch_fun_thread(0xDEADBEEF55AA55ULL, "super FUN thread 2");

    printf("Child thread 1 ID: %lu\n", fun_thread1);
    printf("Child thread 2 ID: %lu\n", fun_thread2);

    pthread_join(fun_thread1, NULL);
    pthread_join(fun_thread2, NULL);

    puts("We are done having fun :(");
    return EXIT_SUCCESS;
}

