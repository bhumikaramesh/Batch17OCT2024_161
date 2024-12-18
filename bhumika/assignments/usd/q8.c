#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

typedef struct {
    char *name;      
    int percentage;  
} Record;

int parse_input(char *input, Record **records) {
    int record_count = 0;
    char *token;
    
    token = strtok(input, ";");
    while (token != NULL) {
        record_count++;
        token = strtok(NULL, ";");
    }
    
    *records = (Record *)malloc(record_count * sizeof(Record));
    if (*records == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    token = strtok(input, ";");
    int i = 0;
    while (token != NULL) {
        char *name_token = strtok(token, ",");
        char *percentage_token = strtok(NULL, ",");
        
        (*records)[i].name = (char *)malloc((strlen(name_token) + 1) * sizeof(char));
        if ((*records)[i].name == NULL) {
            printf("Memory allocation failed for name!\n");
            exit(1);
        }
        strcpy((*records)[i].name, name_token);
        
        (*records)[i].percentage = atoi(percentage_token);
        
        i++;
        token = strtok(NULL, ";");
    }
    
    return record_count;
}

void display_records(Record *records, int record_count) {
    printf("No. of records: %d\n", record_count);
    
    for (int i = 0; i < record_count; i++) {
        printf("Record %d:\n", i + 1);
        printf("Name: %s, Percentage: %d\n", records[i].name, records[i].percentage);
    }
}

void free_records(Record *records, int record_count) {
    for (int i = 0; i < record_count; i++) {
        free(records[i].name);  
    }
    free(records);  
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s \"<input_string>\"\n", argv[0]);
        return 1;
    }

    char *input = strdup(argv[1]);
    if (input == NULL) {
        printf("Memory allocation failed for input string!\n");
        return 1;
    }

    Record *records = NULL;
    int record_count = parse_input(input, &records);
    
    display_records(records, record_count);
    
    free_records(records, record_count);

    free(input);
    
    return 0;
}

