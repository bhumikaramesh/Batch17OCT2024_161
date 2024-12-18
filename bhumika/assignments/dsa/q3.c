#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ID_LEN 6 

typedef struct node {
    char id[MAX_ID_LEN];  
    int val;               
    char *name;            
    struct node *next;     
} Node;

Node* createNode(char *id, char *name, int val) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    strncpy(newNode->id, id, MAX_ID_LEN);  
    newNode->id[MAX_ID_LEN - 1] = '\0';    
    newNode->val = val;

    newNode->name = (char*)malloc(strlen(name) + 1);
    if (newNode->name == NULL) {
        printf("Memory allocation failed for name!\n");
        free(newNode);
        exit(1);
    }
    strcpy(newNode->name, name);

    newNode->next = NULL; 
    return newNode;
}

void printList(Node *head) {
    while (head != NULL) {
        printf("ID: %s, Name: %s, Value: %d\n", head->id, head->name, head->val);
        head = head->next;
    }
}

int search_update_name(Node **head, char *search, char *replace) {
    Node *current = *head;
    while (current != NULL) {
        if (strcmp(current->name, search) == 0) {
        
            free(current->name);  
            current->name = (char*)malloc(strlen(replace) + 1); 
            strcpy(current->name, replace);
            return 1;  
        }
        current = current->next;
    }
    return 0;  
}

int sorted_insert_name(Node **head, char *name, int val) {
    Node *newNode = createNode("00000", name, val);  

    if (*head == NULL || strcmp((*head)->name, name) > 0) {
        newNode->next = *head;
        *head = newNode;
        return 1;
    }

    Node *current = *head;
    while (current->next != NULL && strcmp(current->next->name, name) < 0) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
    return 1;
}

int sorted_insert_val(Node **head, char *name, int val) {
    Node *newNode = createNode("00000", name, val);  

    if (*head == NULL || (*head)->val > val) {
        newNode->next = *head;
        *head = newNode;
        return 1;
    }

    Node *current = *head;
    while (current->next != NULL && current->next->val < val) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
    return 1;
}

void freeList(Node *head) {
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp->name);  
        free(temp);        
    }
}

int main() {
    Node *head = NULL;

    sorted_insert_name(&head, "John", 10);
    sorted_insert_name(&head, "Alice", 20);
    sorted_insert_name(&head, "Bob", 15);

    printf("Initial List:\n");
    printList(head);

    search_update_name(&head, "Bob", "Charlie");

    printf("\nAfter update (Bob -> Charlie):\n");
    printList(head);

    sorted_insert_val(&head, "David", 5);
    sorted_insert_val(&head, "Eve", 18);

    printf("\nAfter inserting by value:\n");
    printList(head);

    freeList(head);

    return 0;
}

