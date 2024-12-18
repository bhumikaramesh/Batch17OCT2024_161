#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int uint;

typedef struct {
    char *name;
    uint age;
} Person;

int main() {
    Person persons[5];
    for (int i = 0; i < 5; i++) {
        persons[i].name = (char *)malloc(50 * sizeof(char));
  }
    for (int i = 0; i < 5; i++) {
        printf("Enter name for person %d: ", i + 1);
        fgets(persons[i].name, 50, stdin);
        persons[i].name[strcspn(persons[i].name, "\n")] = '\0'; 
        
        printf("Enter age for person %d: ", i + 1);
        scanf("%u", &persons[i].age);
        getchar();
    }
    FILE *outFile = fopen("out.bin", "wb");
    if (outFile == NULL) {
        printf("Error opening file.\n");
        return -1;
    }
    for (int i = 0; i < 5; i++) {
        fwrite(persons[i].name, sizeof(char), 20, outFile);
        fwrite(&persons[i].age, sizeof(uint), 1, outFile);
    }
    fclose(outFile);
    FILE *inFile = fopen("out.bin", "rb");
    if (inFile == NULL) {
        printf("Error opening file.\n");
        return -1;
    }
    Person tempPerson;
    for (int i = 0; i < 5; i++) {
        fread(tempPerson.name, sizeof(char), 20, inFile);
        fread(&tempPerson.age, sizeof(uint), 1, inFile);
        printf("Read from file - Name: %s, Age: %u\n", tempPerson.name, tempPerson.age);
    }
    fclose(inFile);
    for (int i = 0; i < 5; i++) {
        printf("Original data - Name: %s, Age: %u\n", persons[i].name, persons[i].age);
    }
    printf("\nSize of each name (20 bytes) + size of age (4 bytes) = %zu bytes\n", sizeof(char) * 20 + sizeof(uint));
    printf("Total size for 2 name-age pairs: %zu bytes\n", 2 * (sizeof(char) * 20 + sizeof(uint)));
    FILE *file = fopen("out.bin", "rb");
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fclose(file);
    printf("Size of the file: %ld bytes\n", fileSize);
    for (int i = 0; i < 5; i++) {
        free(persons[i].name);
    }

    return 0;
}

