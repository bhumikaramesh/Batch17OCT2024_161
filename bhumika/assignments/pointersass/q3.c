#include <stdio.h>
#include <string.h>

#define MAX 80
#define SUCCESS 0
#define FAILURE 1

// Function to search for a character and insert '_' after it.
int search_insert(char name[], char search_char) {
    int i, j;
    int length = strlen(name);
    
    for (i = 0; i < length; i++) {
        if (name[i] == search_char){
            for (j = length; j >= i; j--) {
                name[j + 1] = name[j];  
            }
            name[i + 1] = '_';
            name[length + 1] = '\0';
            
            return SUCCESS; 
        }
    }
    return FAILURE;  
}
int main() {
    char name[MAX] = "ABC";
    char search_char = 'B';  
    int ret = search_insert(name, search_char);
    
    if (ret == SUCCESS) {
        printf("Updated string: %s\n", name);
    } else {
        printf("Character not found.\n");
    }
    
    return 0;
}

