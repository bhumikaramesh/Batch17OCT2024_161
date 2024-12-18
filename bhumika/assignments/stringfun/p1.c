#include <stdio.h>
#include <string.h>

int tokenise(char *arr) {
    char *token;
    int count = 0;

    // Tokenize the string using space as a delimiter
    token = strtok(arr, " ");
    
    while (token != NULL) {
        printf("Token %d: %s\n", ++count, token);
        token = strtok(NULL, " "); // Get the next token
    }

    return count;
}

int main() {
    char str[100];
    printf("Enter a line of text: ");
    fgets(str, sizeof(str), stdin); 
    
   
    str[strcspn(str, "\n")] = 0;
    
  
    int num_tokens = tokenise(str);
    printf("Total number of tokens: %d\n", num_tokens);
    
    return 0;
}

