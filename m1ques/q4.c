#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_LEN 100

// Function to perform bubble sort based on genre
void bubbleSort(char **books[], int n) {
    int i, j;
    char *temp[3];

    // Bubble Sort Algorithm
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(books[j][2], books[j + 1][2]) > 0) {
                // Swap the entire book record (title, author, genre)
                for (int k = 0; k < 3; k++) {
                    temp[k] = books[j][k];
                    books[j][k] = books[j + 1][k];
                    books[j + 1][k] = temp[k];
                }
            }
        }
    }
}

int main() {
    int N;
    char buffer[MAX_LEN];

    // Input the number of books
    scanf("%d", &N);
    getchar(); // To consume the newline character after the number

    // Declare a 2D array of pointers (double pointers)
    char **books[MAX_BOOKS];

    // Input book details
    for (int i = 0; i < N; i++) {
        books[i] = (char **)malloc(3 * sizeof(char *)); // Allocate memory for 3 columns (title, author, genre)

        // Allocate memory for title, author, and genre
        for (int j = 0; j < 3; j++) {
            books[i][j] = (char *)malloc(MAX_LEN * sizeof(char));
        }

        // Read book details (title, author, genre)
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%[^,],%[^,],%[^\n]", books[i][0], books[i][1], books[i][2]);
    }

    // Sort the books based on their genre
    bubbleSort(books, N);

    // Output the sorted book titles
    for (int i = 0; i < N; i++) {
        printf("%s\n", books[i][0]);
    }

    // Free the dynamically allocated memory
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            free(books[i][j]); // Free memory for each string (title, author, genre)
        }
        free(books[i]); // Free the memory for the book record
    }

    return 0;
}

