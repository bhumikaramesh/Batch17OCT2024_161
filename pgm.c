#include <stdio.h>
#include <string.h>
struct Employee {
    int id;
    char firstName[30];
    char lastName[30];
    float salary;
};

typedef struct Employee EMP;
// Function prototypes
void getdetailsEmployees( EMP[], int *count);
void displaydetailsEmployees(EMP[], int count);
void searchforEmployeeById (EMP[], int count, int id);
void searchforEmployeeByLastName(EMP[], int count, char lastName[]);
void searchforEmployeesBySalaryRange(EMP[], int count, float minSalary, float maxSalary);
void updateEmployeelastName(EMP[], int count, int id, char newLastName[]);

int main() {
 
    int employeeCount = 0;
    int choice, id;
    char lastName[30], newLastName[30];
    float minSalary = 6000, maxSalary = 10000;

    while(1) {
        printf("\nMenu:\n");
        printf("1. input employee records\n");
        printf("2. Display all employee records\n");
        printf("3. Search for employee by ID\n");
        printf("4. Search for employee by Last Name\n");
        printf("5. Search for  employees with salary between 6K-10K\n");
        printf("6. Update employee last name\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                getdetailsofEmployees(employees, &employeeCount);
                break;
            case 2:
                displaydetailsEmployees(employees, employeeCount);
                break;
            case 3:
                printf("Enter employee ID to search: ");
                scanf("%d", &id);
                searchEmployeeById(employees, employeeCount, id);
                break;
            case 4:
                printf("Enter last name to search: ");
                scanf("%s", lastName);
                searchEmployeeByLastName(employees, employeeCount, lastName);
                break;
            case 5:
                searchEmployeesBySalaryRange(employees, employeeCount, minSalary, maxSalary);
                break;
            case 6:
                printf("Enter employee ID to update last name: ");
                scanf("%d", &id);
                printf("Enter new last name: ");
                scanf("%s", newLastName);
                updateEmployeeLastName(employees, employeeCount, id, newLastName);
                break;
            case 7:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}


void getdetailsofEmployees(EMP[], int *count) {
    int n, i;
    printf("Enter number of employees: ");
    scanf("%d", &n);

    for(i =count; i <count + n; i++) {
        printf("Enter details for employee %d\n", i + 1);
        printf("ID: ");
        scanf("%d", &employees[i].id);
        printf("First Name: ");
        scanf("%s", employees[i].firstName);
        printf("Last Name: ");
        scanf("%s", employees[i].lastName);
        printf("Salary: ");
        scanf("%f", &employees[i].salary);
    }

    *count += n;
}

void displaydetailsofEmployees(EMP[], int count) {
    if(count == 0) {
        printf("No employee records found.\n");
        return;
    }
    printf("\nEmployee Records:\n");
    for(int i = 0; i < count; i++) {
        printf("ID: %d, First Name: %s, Last Name: %s, Salary: %f\n",
               employees[i].id, employees[i].firstName, employees[i].lastName, employees[i].salary);
    }
}


void searchforEmployeeById(EMP[], int count, int id) {
    int found = 0;
    for(int i = 0; i < count; i++) {
        if(employees[i].id == id) {
            printf("Employee found: ID: %d, First Name: %s, Last Name: %s, Salary: %f\n",
                   employees[i].id, employees[i].firstName, employees[i].lastName, employees[i].salary);
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("Employee with ID %d not found.\n", id)
void searchforEmployeeByLastName(struct Employee employees[], int count, char lastName[]) {
    int found = 0;
    for(int i = 0; i < count; i++) {
        if(strcmp(employees[i].lastName, lastName) == 0) {
            printf("Employee found: ID: %d, First Name: %s, Last Name: %s, Salary: %f\n",
                   employees[i].id, employees[i].firstName, employees[i].lastName, employees[i].salary);
            found = 1;
        }
    }
    if(!found) {
        printf("No employee found with last name %s.\n", lastName);
    }
}
void searchforEmployeesBySalaryRange(struct Employee employees[], int count, float minSalary, float maxSalary) {
    int found = 0;
    printf("\nEmployees with salary between %.2f and %.2f:\n", minSalary, maxSalary);
    for(int i = 0; i < count; i++) {
        if(employees[i].salary >= minSalary && employees[i].salary <= maxSalary) {
            printf("ID: %d, First Name: %s, Last Name: %s, Salary: %.2f\n",
                   employees[i].id, employees[i].firstName, employees[i].lastName, employees[i].salary);
            found = 1;
        }
    }
    if(!found) {
        printf("No employees found in the specified salary range.\n");
    }
}
void updateEmployeeLastName(struct Employee employees[], int count, int id, char newLastName[]) {
    int found = 0;
    for(int i = 0; i < count; i++) {
        if(employees[i].id == id) {
            strcpy(employees[i].lastName, newLastName);
            printf("Last name updated for employee ID %d to %s.\n", id, newLastName);
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("Employee with ID %d not found.\n", id);
    }
}

