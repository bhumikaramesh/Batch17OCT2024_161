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

int update(EMP *emp) {
    printf("Updating employee details...\n");

    printf("Enter new name (max 50 characters): ");
    getchar(); 
    fgets(emp->name, MAX_NAME_LENGTH, stdin);
    emp->name[strcspn(emp->name, "\n")] = 0;

    printf("Enter new age: ");
    scanf("%u", &emp->age);

    printf("Enter new designation (0: MANAGER, 1: DEVELOPER, 2: DESIGNER, 3: TESTER): ");
    int des;
    scanf("%d", &des);
    emp->designation = (Designation)des;

    return 1; 
}

EMP copy(EMP emp) {
    EMP new_emp;
    new_emp.name = (char *)malloc(strlen(emp.name) + 1);
    if (new_emp.name == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    strcpy(new_emp.name, emp.name);
    new_emp.age = emp.age;
    new_emp.designation = emp.designation;

    return new_emp;
}

int main() {
    EMP emp;

    read(&emp);

    display(emp);

    update(&emp);

    display(emp);

    EMP new_emp = copy(emp);
    display(new_emp);

    free(emp.name);
    free(new_emp.name);

    return 0;
}

