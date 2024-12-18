
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 80

typedef struct node_q {
    int int_data;       
    char *data;         
    struct node_q *next; 
} node;

typedef struct queue {
    node *front;
    node *rear;
} queue;

void initQueue(queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

int isEmpty(queue *q) {
    return q->front == NULL;
}

void enqueue(queue *q, const char *str) {
    node *newNode = (node *)malloc(sizeof(node)); // Allocate memory for the new node
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->int_data = 0;
    newNode->data = (char *)malloc((strlen(str) + 1) * sizeof(char)); 
    if (newNode->data == NULL) {
        printf("Memory allocation for string failed!\n");
        exit(1);
    }

    strcpy(newNode->data, str);

    newNode->next = NULL; 

    if (isEmpty(q)) {
        q->front = newNode; 
        q->rear = newNode;  
    } else {
        q->rear->next = newNode; 
        q->rear = newNode;      
    }
}

char *dequeue(queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return NULL;
    }

    node *temp = q->front; 
    char *result = temp->data; 

    q->front = q->front->next;
    if (q->front == NULL) { 
        q->rear = NULL;
    }

    free(temp); 
    return result;
}

void displayQueue(queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    node *temp = q->front;
    while (temp != NULL) {
        printf("%s\n", temp->data); 
        temp = temp->next;
    }
}

void freeQueue(queue *q) {
    while (!isEmpty(q)) {
        char *str = dequeue(q);
        free(str); 
    }
}

int main() {
    queue q;
    initQueue(&q);

    int n;
    char str[MAX_STRING_LENGTH + 1];

    printf("Enter the number of strings to enqueue: ");
    scanf("%d", &n);
    getchar(); 

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

