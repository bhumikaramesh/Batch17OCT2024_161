#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_BUF_SIZE 1024

// Function to execute 'grep' command to search a word in a file
int search_in_file(const char *file, const char *search_term) {
    char command[MAX_BUF_SIZE];
    
    // Prepare the grep command to search for the word in the file
    snprintf(command, sizeof(command), "grep -l '%s' %s", search_term, file);

    // Open the process to execute the command
    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        perror("Error opening grep");
        return 0;
    }

    char buffer[MAX_BUF_SIZE];
    int found = 0;
    
    // Read the output of the grep command (list of files containing the word)
    if (fgets(buffer, sizeof(buffer), fp) != NULL) {
        found = 1; // Word found in the file
    }

    fclose(fp);
    return found;
}

// Function to search the word inside the selected file
int search_word_in_selected_file(const char *file, const char *search_term) {
    char command[MAX_BUF_SIZE];
    snprintf(command, sizeof(command), "grep -q '%s' %s", search_term, file);

    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        perror("Error opening grep");
        return 0;
    }

    int result = pclose(fp); // Get the result of the grep command

    return (result == 0);  // 0 indicates the word was found
}

// Function to list files containing the search word in a given directory
void list_files_with_word(const char *directory, const char *search_string) {
    DIR *dir = opendir(directory);
    if (dir == NULL) {
        perror("Failed to open directory");
        return;
    }

    struct dirent *entry;
    int file_count = 0;
    char matching_files[MAX_BUF_SIZE][MAX_BUF_SIZE];  // Store file names with matches

    // Loop through the directory entries
    while ((entry = readdir(dir)) != NULL) {
        // Skip directories and hidden files (starting with a dot)
        if (entry->d_type == DT_DIR || entry->d_name[0] == '.') {
            continue;
        }

        // Build the full file path
        char file_path[MAX_BUF_SIZE];
        snprintf(file_path, sizeof(file_path), "%s/%s", directory, entry->d_name);

        // Search the file for the word using 'grep'
        if (search_in_file(file_path, search_string)) {
            // If word is found, store the file name
            strcpy(matching_files[file_count++], file_path);
        }
    }

    if (file_count == 0) {
        printf("No files found containing the word '%s'.\n", search_string);
    } else {
        // List files that contain the search word
        printf("Files containing the word '%s':\n", search_string);
        for (int i = 0; i < file_count; i++) {
            printf("%d. %s\n", i + 1, matching_files[i]);
        }

        // Allow user to choose a file
        int file_choice;
        printf("\nEnter the number of the file to search for the word again: ");
        scanf("%d", &file_choice);

        if (file_choice > 0 && file_choice <= file_count) {
            // Search the selected file for the word again
            if (search_word_in_selected_file(matching_files[file_choice - 1], search_string)) {
                printf("The word '%s' was found in the file '%s'.\n", search_string, matching_files[file_choice - 1]);
            } else {
                printf("The word '%s' was NOT found in the file '%s'.\n", search_string, matching_files[file_choice - 1]);
            }
        } else {
            printf("Invalid choice.\n");
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

    // Ask the user for the search term (word, string, or sentence)
    printf("Enter the string, word, or sentence to search: ");
    fgets(search_term, sizeof(search_term), stdin);
    search_term[strcspn(search_term, "\n")] = 0;  // Remove the newline character

    // Call the function to list files containing the search term
    list_files_with_word(directory, search_term);

    return 0;
}

