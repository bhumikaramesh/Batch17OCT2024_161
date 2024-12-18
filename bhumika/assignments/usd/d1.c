#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 80

char *process_string(char *line) {
    char *token;
    char *delimiters = " \t";  
    size_t buffer_size = MAX_LINE_LENGTH * 2;  
    char *result = malloc(buffer_size); 
    if (result == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    result[0] = '\0';  

    token = strtok(line, delimiters); 

    while (token != NULL) {
        if (strlen(result) > 0) {
            strcat(result, "_");
        }
    
        strcat(result, token);
        token = strtok(NULL, delimiters);  
    }

    return result;  
}

int main() {
    char line[MAX_LINE_LENGTH];

    printf("Enter a line of text (max 80 characters): ");
    fgets(line, sizeof(line), stdin);

    line[strcspn(line, "\n")] = '\0';

    char *result = process_string(line);

    printf("Concatenated string: %s\n", result);

    free(result);

    return 0;
}

