#include <stdio.h>
#include <string.h>

#define MAX 80
#define SUCCESS 0
#define FAILURE -1

// Function declaration
int search_insert(char name[], char search_char);

int main()
{
    char name[MAX] = "ABC";  // Example string, you can modify this to test
    char search_char = 'B';  // Character to search for

    // Call the search_insert function
    int ret = search_insert(name, search_char);

    // Check the return value and print updated string if successful
    if (ret == SUCCESS) {
        printf("Updated string: %s\n", name);
    } else {
        printf("Character not found or no space for insertion.\n");
    }

    return 0;
}


int search_insert(char name[], char search_char)
{
    int i, length;

    // Find the length of the string
    length = strlen(name);

    // Search for the character in the string
    for (i = 0; i < length; i++) {
        if (name[i] == search_char) {
            // Shift all characters after the found character one position to the right
            if (length < MAX - 1) {  // Check if there is space for the underscore and one more character
                for (int j = length; j > i; j--) {
                    name[j] = name[j - 1];
                }

                // Insert the underscore after the found character
                name[i + 1] = '_';

                // Null-terminate the string after the new character
                name[i + 2] = '\0';

                return SUCCESS;
            } else {
                // If there is no space left to insert the character, return FAILURE
                return FAILURE;
            }
        }
    }

    // If the character is not found, return FAILURE
    return FAILURE;
}
