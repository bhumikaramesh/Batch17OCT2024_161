#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define THREAD1_INTERVAL 2
#define THREAD2_INTERVAL 3
#define THREAD3_INTERVAL 3
#define CANCEL_TIME 180 

typedef struct {
    pthread_t thread_id;
    int detached;
    int cancel_type;
    int cancel_status;
} thread_info_t;

void *thread1_function(void *arg) {
    thread_info_t *t_info = (thread_info_t *)arg;
    time_t now;
    struct tm *timeinfo;

    while (1) {
        time(&now);
        timeinfo = localtime(&now);
        printf("%s Thread ID: %lu | Detach: %d | Cancel Type: %d | Cancel Status: %d | Health OK\n",
               asctime(timeinfo), t_info->thread_id, t_info->detached, t_info->cancel_type, t_info->cancel_status);
        sleep(THREAD1_INTERVAL);
    }
    return NULL;
}


void *thread2_function(void *arg) {
    thread_info_t *t_info = (thread_info_t *)arg;
    int count = 1000;
    time_t now;
    struct tm *timeinfo;

    while (1) {
        time(&now);
        timeinfo = localtime(&now);
        printf("%s Thread ID: %lu | Detach: %d | Cancel Type: %d | Cancel Status: %d | %d\n",
               asctime(timeinfo), t_info->thread_id, t_info->detached, t_info->cancel_type, t_info->cancel_status, count);
        count += 2;
        sleep(THREAD2_INTERVAL);
    }
    return NULL;
}

void *thread3_function(void *arg) {
    thread_info_t *t_info = (thread_info_t *)arg;
    int count = 2000;
    time_t now;
    struct tm *timeinfo;

    while (1) {
        time(&now);
        timeinfo = localtime(&now);
        printf("%s Thread ID: %lu | Detach: %d | Cancel Type: %d | Cancel Status: %d | %d\n",
               asctime(timeinfo), t_info->thread_id, t_info->detached, t_info->cancel_type, t_info->cancel_status, count);
        count += 2;
        sleep(THREAD3_INTERVAL);
    }
    return NULL;
}

void create_thread(pthread_t *thread, thread_info_t *t_info, void *(*func)(void *)) {
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    if (t_info->detached) {
        pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    } else {
        pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    }

    pthread_create(thread, &attr, func, t_info);
    t_info->thread_id = *thread;

    if (t_info->cancel_type == PTHREAD_CANCEL_ENABLE) {
        pthread_setcanceltype(t_info->cancel_status, NULL);
    }
}

void cancel_threads(pthread_t thread1, pthread_t thread2, pthread_t thread3) {
    sleep(CANCEL_TIME);

    printf("Canceling all threads after 3 minutes...\n");

    pthread_cancel(thread1);
    pthread_cancel(thread2);
    pthread_cancel(thread3);
}

int main() {
    pthread_t thread1, thread2, thread3;
    thread_info_t t_info1 = { .detached = 1, .cancel_type = PTHREAD_CANCEL_DISABLE, .cancel_status = PTHREAD_CANCEL_DISABLE };
    thread_info_t t_info2 = { .detached = 0, .cancel_type = PTHREAD_CANCEL_ENABLE, .cancel_status = PTHREAD_CANCEL_DEFERRED };
    thread_info_t t_info3 = { .detached = 0, .cancel_type = PTHREAD_CANCEL_ENABLE, .cancel_status = PTHREAD_CANCEL_ASYNCHRONOUS };

    printf("Creating threads...\n");

    create_thread(&thread1, &t_info1, thread1_function);
    create_thread(&thread2, &t_info2, thread2_function);
    create_thread(&thread3, &t_info3, thread3_function);

    printf("Thread 1 | Detached: %d | Cancel Type: %d | Cancel Status: %d\n", t_info1.detached, t_info1.cancel_type, t_info1.cancel_status);
    printf("Thread 2 | Detached: %d | Cancel Type: %d | Cancel Status: %d\n", t_info2.detached, t_info2.cancel_type, t_info2.cancel_status);
    printf("Thread 3 | Detached: %d | Cancel Type: %d | Cancel Status: %d\n", t_info3.detached, t_info3.cancel_type, t_info3.cancel_status);

    cancel_threads(thread1, thread2, thread3);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    printf("All threads have been canceled and joined.\n");

    return 0;
}

