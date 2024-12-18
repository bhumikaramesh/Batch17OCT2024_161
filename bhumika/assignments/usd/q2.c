#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 100  

typedef struct {
    char name[MAX_NAME_LENGTH];  
    unsigned char age:7;         
} Person;

void printPersonDetails(Person p) {
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
}

int main() {
    Person person;

    strncpy(person.name, "John Doe", MAX_NAME_LENGTH);

    person.age = 25;

    printPersonDetails(person);

    return 0;
}

