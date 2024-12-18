#include <stdio.h>
#include <string.h>
#include <ctype.h>

void replace_vowels_with_ay(char *word) {
    int len = strlen(word);
    char temp[100]; // Temporary array to hold the new word
    int j = 0;

    for (int i = 0; i < len; i++) {
        // Check if the character is a vowel (both lowercase and uppercase)
        if (strchr("aeiouAEIOU", word[i])) {
            temp[j++] = 'a'; // Add 'a' for vowel replacement
            temp[j++] = 'y'; // Add 'y' for vowel replacement
        } else {
            temp[j++] = word[i]; // Copy the character as is
        }
    }
    temp[j] = '\0'; // Null terminate the new word

    // Copy the result back into the original word
    strcpy(word, temp);
}

int main() {
    char word[41]; // Max word length of 40 characters + 1 for null terminator

    printf("Enter a word (max 40 characters): ");
    fgets(word, sizeof(word), stdin);
    
    // Remove the newline character if present
    word[strcspn(word, "\n")] = 0;

    // Call the function to replace vowels with "ay"
    replace_vowels_with_ay(word);
    
    printf("Updated word: %s\n", word);
    
    return 0;
}

