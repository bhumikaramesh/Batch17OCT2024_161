#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>

#define MAX_BUF_SIZE 1024

// Function to search for a word in a file
int search_in_file(const char *filename, const char *search_string) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return 0;
    }

    char buffer[MAX_BUF_SIZE];
    while (fgets(buffer, sizeof(buffer), file)) {
        if (strstr(buffer, search_string)) {  // Search for substring
            fclose(file);
            return 1; // Match found
        }
    }

    fclose(file);
    return 0; // No match found
}

// Function to list files in a directory containing the search string
void list_files_with_word(const char *directory, const char *search_string, int pipe_fd) {
    DIR *dir = opendir(directory);
    if (dir == NULL) {
        perror("Failed to open directory");
        write(pipe_fd, "Error opening directory", 23);
        return;
    }

    struct dirent *entry;
    int found = 0;

    while ((entry = readdir(dir)) != NULL) {
        // Skip directories and hidden files (starting with dot)
        if (entry->d_type == DT_DIR || entry->d_name[0] == '.') {
            continue;
        }

        if (search_in_file(entry->d_name, search_string)) {
            // If word is found in the file, write the file name to the pipe
            write(pipe_fd, entry->d_name, strlen(entry->d_name) + 1);
            found = 1;
        }
    }

    if (!found) {
        write(pipe_fd, "No files found", 15);
    }

    closedir(dir);
}

// Function to open and display contents of a selected file
void display_file_contents(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    char buffer[MAX_BUF_SIZE];
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <search_word> <directory_path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *search_string = argv[1];
    const char *directory = argv[2];

    int pipe_fd[2];
    if (pipe(pipe_fd) == -1) {
        perror("Pipe creation failed");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process: Perform the search and list files containing the word
        close(pipe_fd[0]);  // Close unused read end of pipe
        list_files_with_word(directory, search_string, pipe_fd[1]);
        close(pipe_fd[1]);  // Close write end after use
        exit(EXIT_SUCCESS);
    } else {
        // Parent process: Read the result from the pipe and display the list of files
        close(pipe_fd[1]);  // Close unused write end of pipe

        char buffer[MAX_BUF_SIZE];
        int file_count = 0;

        // Read and display filenames containing the search string
        printf("Files containing the word '%s':\n", search_string);
        while (read(pipe_fd[0], buffer, sizeof(buffer)) > 0) {
            if (strcmp(buffer, "No files found") == 0) {
                printf("No files found containing the word '%s'.\n", search_string);
                break;
            }
            printf("%d. %s\n", ++file_count, buffer);
        }

        close(pipe_fd[0]);  // Close read end after use

        if (file_count > 0) {
            // Ask user to choose a file
            int file_choice;
            printf("Enter the number of the file to open: ");
            scanf("%d", &file_choice);

            // Re-read the filenames and open the selected file
            FILE *file_list = fopen("file_list.txt", "r");
            if (!file_list) {
                perror("Error opening file list");
                exit(EXIT_FAILURE);
            }

            fseek(file_list, 0, SEEK_SET);  // Reset file pointer
            for (int i = 0; i < file_choice; i++) {
                fgets(buffer, sizeof(buffer), file_list);
            }

            fclose(file_list);
            // Display the contents of the selected file
            display_file_contents(buffer);
        }

        wait(NULL);  // Wait for the child process to finish
    }

    return 0;
}

