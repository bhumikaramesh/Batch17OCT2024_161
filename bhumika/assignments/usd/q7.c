#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

typedef enum {
    MANAGER,
    DEVELOPER,
    DESIGNER,
    TESTER
} Designation;

typedef struct {
    char *name;               
    unsigned int age;         
    Designation designation;  
} EMP;

void read(EMP *emp) {
    emp->name = (char *)malloc(MAX_NAME_LENGTH * sizeof(char));
    if (emp->name == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    printf("Enter name (max 50 characters): ");
    fgets(emp->name, MAX_NAME_LENGTH, stdin);
    emp->name[strcspn(emp->name, "\n")] = 0;

    printf("Enter age: ");
    scanf("%u", &emp->age);

    printf("Enter designation (0: MANAGER, 1: DEVELOPER, 2: DESIGNER, 3: TESTER): ");
    int des;
    scanf("%d", &des);
    emp->designation = (Designation)des;
}

void display(EMP emp) {
    const char *designation_names[] = {"MANAGER", "DEVELOPER", "DESIGNER", "TESTER"};
    printf("\nEmployee Details:\n");
    printf("Name: %s\n", emp.name);
    printf("Age: %u\n", emp.age);
    printf("Designation: %s\n", designation_names[emp.designation]);
}

int main() {
    EMP arr[3];  

    for (int i = 0; i < 3; i++) {
        printf("\nEnter details for Employee %d:\n", i + 1);
        read(&arr[i]);
        display(arr[i]);
    }

    for (int i = 0; i < 3; i++) {
        free(arr[i].name);
    }

    return 0;
}

