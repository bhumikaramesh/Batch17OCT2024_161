#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_BUF_SIZE 1024

// Function to search for a word in a file
int search_in_file(const char *filename, const char *word) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return 0;
    }

    char buffer[MAX_BUF_SIZE];
    while (fgets(buffer, sizeof(buffer), file)) {
        if (strstr(buffer, word)) {
            fclose(file);
            return 1; // Match found
        }
    }

    fclose(file);
    return 0; // No match found
}

// Function to recursively search files in a directory
void search_directory(const char *dir_name, const char *word, int write_fd) {
    DIR *dir = opendir(dir_name);
    if (!dir) {
        perror("Failed to open directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char path[MAX_BUF_SIZE];
        snprintf(path, sizeof(path), "%s/%s", dir_name, entry->d_name);

        if (entry->d_type == DT_DIR) {
            // If it's a directory, recurse into it
            search_directory(path, word, write_fd);
        } else if (entry->d_type == DT_REG) {
            // If it's a regular file, search for the word
            if (search_in_file(path, word)) {
                // If match found, write the file name to the pipe
                write(write_fd, path, strlen(path) + 1);
            }
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <word_to_search> <starting_directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *word = argv[1];
    const char *start_dir = argv[2];

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
        // Child process: Perform the search
        close(pipe_fd[0]);  // Close unused read end

        // Start searching from the given directory
        search_directory(start_dir, word, pipe_fd[1]);

        close(pipe_fd[1]);  // Close write end after use
        exit(EXIT_SUCCESS);
    } else {
        // Parent process: Read from pipe and print results
        close(pipe_fd[1]);  // Close unused write end

        char buffer[MAX_BUF_SIZE];
        ssize_t bytes_read;
        while ((bytes_read = read(pipe_fd[0], buffer, sizeof(buffer))) > 0) {
            printf("Match found in: %s\n", buffer);
        }

        close(pipe_fd[0]);  // Close read end after use

        // Wait for child process to finish
        wait(NULL);
    }

    return 0;
}

