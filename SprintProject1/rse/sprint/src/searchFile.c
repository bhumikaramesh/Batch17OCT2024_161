#include<common.h>
#include<functions.h>


/*char *searchForFile(char *filename) {
	
	char *resolvedPath = (char *)malloc(PATH_MAX);
    
    if (realpath(filename, resolvedPath) != NULL) {
        return resolvedPath; // Return the absolute path if file exists
    }
	else {
        free(resolvedPath); // Free memory if the file doesn't exist
        return NULL; // Return NULL if file does not exist
    }
}*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

char *searchForFile(char *filename) {
    const char *homeDir = "/home2/user46";  // Hardcoded home directory
    if (homeDir == NULL) {
        fprintf(stderr, "Home directory not found\n");
        return NULL;
    }

    // Use a pipe to capture the output of the find command
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return NULL;
    }

    // Create a child process to run the find command
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return NULL;
    }

    if (pid == 0) {  // Child process
        // Close the unused write end of the pipe
        close(pipefd[0]);

        // Redirect the standard output to the pipe
        if (dup2(pipefd[1], STDOUT_FILENO) == -1) {
            perror("dup2");
            exit(1);
        }

        // Execute the find command to search for the file in the home directory
        execlp("find", "find", homeDir, "-name", filename, (char *)NULL);
        perror("execlp");  // If execlp fails
        exit(1);
    } else {  // Parent process
        // Close the unused write end of the pipe
        close(pipefd[1]);

        // Wait for the child process to finish
        wait(NULL);

        // Read the output of the find command from the pipe
        char *resolvedPath = (char *)malloc(PATH_MAX);
        if (resolvedPath == NULL) {
            perror("malloc");
            return NULL;
        }

        ssize_t len = read(pipefd[0], resolvedPath, PATH_MAX - 1);
        if (len == -1) {
            perror("read");
            free(resolvedPath);
            return NULL;
        }

        resolvedPath[len] = '\0';  // Null-terminate the string

        // If the output is empty, the file was not found
        if (len == 0) {
            free(resolvedPath);
            return NULL;
        }

        // Close the read end of the pipe
        close(pipefd[0]);

        return resolvedPath;  // Return the resolved file path
    }
}

