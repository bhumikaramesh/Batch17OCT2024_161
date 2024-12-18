#include <stdio.h>

int main() {
    char choice;

    // Input the choice
    printf("Enter your choice (y/Y for Yes, n/N for No): ");
    scanf("%c", &choice);

    // Check the choice and display the corresponding message
    if (choice == 'y' || choice == 'Y') {
        printf("Yes\n");
    } else if (choice == 'n' || choice == 'N') {
        printf("No\n");
    } else {
        printf("Invalid character\n");
        return 1; // Exit the program with an error status
    }

    return 0; // Successfully executed
}

