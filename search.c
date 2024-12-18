#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_BUF_SIZE 1024

// Function to execute the 'grep' command and return the output
void search_with_grep(const char *search_term, const char *file) {
    // Create the command string to run grep
    char command[MAX_BUF_SIZE];
    
    // Format the command to search for the term in the file
    snprintf(command, sizeof(command), "grep -n '%s' %s", search_term, file);

    // Use popen to execute the grep command and get the output
    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        perror("Error opening process for grep");
        return;
    }

    // Read and print the output of the grep command
    char buffer[MAX_BUF_SIZE];
    int found = 0;
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);  // Print each matching line with line numbers
        found = 1;
    }

    if (!found) {
        printf("No matches found for '%s' in the file '%s'.\n", search_term, file);
    }

    fclose(fp);
}

// Function to list files in a directory containing the search string
void list_files_with_word(const char *directory, const char *search_string) {
    DIR *dir = opendir(directory);
    if (dir == NULL) {
        perror("Failed to open directory");
        return;
    }

    struct dirent *entry;
    int found = 0;
    int file_count = 0;
    char matching_files[MAX_BUF_SIZE][MAX_BUF_SIZE];  // Store file names with matches

    while ((entry = readdir(dir)) != NULL) {
        // Skip directories and hidden files (starting with dot)
        if (entry->d_type == DT_DIR || entry->d_name[0] == '.') {
            continue;
        }

        // Check if the search term is found in the file using grep
        char command[MAX_BUF_SIZE];
        snprintf(command, sizeof(command), "grep -l '%s' %s/%s", search_string, directory, entry->d_name);
        
        // Execute the grep command and check if the file contains the search string
        FILE *fp = popen(command, "r");
        if (fp) {
            char buffer[MAX_BUF_SIZE];
            if (fgets(buffer, sizeof(buffer), fp)) {
                // If file contains the word, store the file name
                strcpy(matching_files[file_count++], entry->d_name);
                found = 1;
            }
            fclose(fp);
        }
    }

    if (!found) {
        printf("No files found containing the word '%s'.\n", search_string);
    } else {
        printf("Files containing the word '%s':\n", search_string);
        for (int i = 0; i < file_count; i++) {
            printf("%d. %s\n", i + 1, matching_files[i]);
        }

        // Ask user to select a file
        int file_choice;
        printf("Enter the number of the file to search for the word '%s': ", search_string);
        scanf("%d", &file_choice);

        // Validate choice and search the selected file
        if (file_choice >= 1 && file_choice <= file_count) {
            char selected_file[MAX_BUF_SIZE];
            strcpy(selected_file, matching_files[file_choice - 1]);

            // Build full path for selected file
            char file_path[MAX_BUF_SIZE];
            snprintf(file_path, sizeof(file_path), "%s/%s", directory, selected_file);

            // Now search for the word in the selected file
            printf("\nSearching for the word '%s' in file '%s'...\n", search_string, file_path);
            search_with_grep(search_string, file_path);
        } else {
            printf("Invalid choice!\n");
        }
    }

    closedir(dir);
}

int main() {
    char directory[MAX_BUF_SIZE];
    char search_term[MAX_BUF_SIZE];

    // Ask the user for the directory name
    printf("Enter the directory path to search: ");
    fgets(directory, sizeof(directory), stdin);
    directory[strcspn(directory, "\n")] = 0;  // Remove the newline character

    // Ask the user for the search term (string, word, or sentence)
    printf("Enter the string, word, or sentence to search: ");
    fgets(search_term, sizeof(search_term), stdin);
    search_term[strcspn(search_term, "\n")] = 0;  // Remove the newline character

    // Call the function to list files containing the search term
    list_files_with_word(directory, search_term);

    return 0;
}

