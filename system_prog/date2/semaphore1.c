#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <unistd.h>
#include <string.h>

#define SHM_KEY 0x1234   // Key for shared memory
#define SEM_KEY 0x5678   // Key for semaphore

union semun {
    int val;
};

void producer() {
    int shmid = shmget(SHM_KEY, sizeof(int), IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    int *ptr = (int *)malloc(sizeof(int));
    *ptr = 10;
    *ptr = 20;

    int *shared_data = (int *)shmat(shmid, NULL, 0);
    if (shared_data == (void *)-1) {
        perror("shmat");
        exit(1);
    }

    int semid = semget(SEM_KEY, 1, IPC_CREAT | 0666);
    if (semid < 0) {
        perror("semget");
        exit(1);
    }

    union semun sem_union;
    sem_union.val = 1; // Initialize semaphore to 1
    semctl(semid, 0, SETVAL, sem_union);

    struct sembuf sem_lock = {0, -1, 0};   // Lock semaphore
    struct sembuf sem_unlock = {0, 1, 0};  // Unlock semaphore

    for (int i = 0; i < 5; i++) {
//        semop(semid, &sem_lock, 1);  // Lock semaphore
        *shared_data = i;            // Write data to shared memory
        printf("Producer: Wrote %d to shared memory\n", i);
  //      semop(semid, &sem_unlock, 1);  // Unlock semaphore
        sleep(3);  // Simulate work
    }

    shmdt(shared_data);
}

void consumer() {
    int shmid = shmget(SHM_KEY, sizeof(int), 0666);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    int *shared_data = (int *)shmat(shmid, NULL, 0);
    if (shared_data == (void *)-1) {
        perror("shmat");
        exit(1);
    }

    int semid = semget(SEM_KEY, 1, 0666);
    if (semid < 0) {
        perror("semget");
        exit(1);
    }

    struct sembuf sem_lock = {0, -1, 0};   // Lock semaphore
    struct sembuf sem_unlock = {0, 1, 0};  // Unlock semaphore

    for (int i = 0; i < 5; i++) {
    //    semop(semid, &sem_lock, 1);  // Lock semaphore
        printf("Consumer: Read %d from shared memory\n", *shared_data);
      //  semop(semid, &sem_unlock, 1);  // Unlock semaphore
        sleep(3);  // Simulate work
    }

    shmdt(shared_data);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <producer|consumer>\n", argv[0]);
        exit(1);
    }

    if (strcmp(argv[1], "producer") == 0) {
        producer();
    } else if (strcmp(argv[1], "consumer") == 0) {
        consumer();
    } else {
        fprintf(stderr, "Invalid argument: %s\n", argv[1]);
        exit(1);
    }

    return 0;
}
