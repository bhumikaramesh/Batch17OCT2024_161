#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define SUCCESS 1
#define FAILURE 0

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

char* search_update(char *searchstr, char *replacestr, Record *records, int record_count) {
    for (int i = 0; i < record_count; i++) {
        if (strcmp(records[i].name, searchstr) == 0) {
            free(records[i].name);  
            records[i].name = (char *)malloc((strlen(replacestr) + 1) * sizeof(char));
            if (records[i].name == NULL) {
                printf("Memory allocation failed for new name!\n");
                exit(1);
            }
            strcpy(records[i].name, replacestr);  
            return records[i].name;
        }
    }
    return NULL;  
}

int delete_record(char *searchstr, int percent, Record **records, int *record_count) {
    for (int i = 0; i < *record_count; i++) {
        if ((searchstr && strcmp((*records)[i].name, searchstr) == 0) || 
            (percent && (*records)[i].percentage == percent)) {
            free((*records)[i].name);  
            
            for (int j = i; j < (*record_count) - 1; j++) {
                (*records)[j] = (*records)[j + 1];
            }
            (*record_count)--;  
            *records = (Record *)realloc(*records, (*record_count) * sizeof(Record));  
            return SUCCESS;
        }
    }
    return FAILURE;
}

int copy(char *name, Record **newstudent, Record *records, int record_count) {
    for (int i = 0; i < record_count; i++) {
        if (strcmp(records[i].name, name) == 0) {
            *newstudent = (Record *)malloc(sizeof(Record));
            if (*newstudent == NULL) {
                printf("Memory allocation failed!\n");
                return FAILURE;
            }
            (*newstudent)->name = (char *)malloc((strlen(records[i].name) + 1) * sizeof(char));
            if ((*newstudent)->name == NULL) {
                printf("Memory allocation failed for name!\n");
                return FAILURE;
            }
            strcpy((*newstudent)->name, records[i].name);
            (*newstudent)->percentage = records[i].percentage;
            return SUCCESS;
        }
    }
    return FAILURE;
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
    
    printf("\nUpdating name 'user1' to 'newuser1'.\n");
    char *updated_name = search_update("user1", "newuser1", records, record_count);
    if (updated_name) {
        printf("Updated Name: %s\n", updated_name);
    } else {
        printf("Name not found.\n");
    }

    printf("\nDeleting record with name 'userABC'.\n");
    int delete_status = delete_record("userABC", 0, &records, &record_count);
    if (delete_status == SUCCESS) {
        printf("Record deleted successfully.\n");
    } else {
        printf("Record not found for deletion.\n");
    }

    printf("\nCopying record of 'userX'.\n");
    Record *new_student = NULL;
    int copy_status = copy("userX", &new_student, records, record_count);
    if (copy_status == SUCCESS) {
        printf("Record copied: Name: %s, Percentage: %d\n", new_student->name, new_student->percentage);
        free(new_student->name);  
        free(new_student);        
    } else {
        printf("Record not found for copying.\n");
    }

    free_records(records, record_count);

    free(input);
    
    return 0;
}

