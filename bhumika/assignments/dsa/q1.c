#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 5

typedef struct queue {
    char **data;  
    int front;       
    int rear;        
    int size;        
} queue_t;

void initQueue(queue_t *q) {
    q->data = (char **)malloc(MAX_QUEUE_SIZE * sizeof(char *)); 
    if (q->data == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

int isFull(queue_t *q) {
    return q->size == MAX_QUEUE_SIZE;
}

int isEmpty(queue_t *q) {
    return q->size == 0;
}

void enqueue(queue_t *q, const char *str) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue string: %s\n", str);
        return;
    }
    
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = (char *)malloc((strlen(str) + 1) * sizeof(char));
    if (q->data[q->rear] == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    strcpy(q->data[q->rear], str); 
    q->size++;
}

char *dequeue(queue_t *q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return NULL;
    }

    char *result = q->data[q->front]; 
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    q->size--;

    return result;
}

void displayQueue(queue_t *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    int i = q->front;
    while (i != q->rear) {
        printf("%s ", q->data[i]);
        i = (i + 1) % MAX_QUEUE_SIZE;
    }
    printf("%s\n", q->data[q->rear]); 
}

void freeQueue(queue_t *q) {
    for (int i = 0; i < q->size; i++) {
        free(q->data[(q->front + i) % MAX_QUEUE_SIZE]); 
    }
    free;
}

int main() {
    queue_t q;


    int n;
    printf("Enter the number of strings to enqueue: ");
    scanf("%d", &n);
    getchar(); 
    
    char str[100];
    
    for (int i = 0; i < n; i++) {
        printf("Enter string %d: ", i + 1);
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = '\0'; 
        
        enqueue(&q, str);
    }

    printf("\nQueue contents after enqueue:\n");
    displayQueue(&q);

    printf("\nDequeuing all elements:\n");
    while (!isEmpty(&q)) {
        char *dequeuedStr = dequeue(&q);
        printf("Dequeued: %s\n", dequeuedStr);
        free(dequeuedStr); 
    }

    freeQueue(&q);

    return 0;
}

