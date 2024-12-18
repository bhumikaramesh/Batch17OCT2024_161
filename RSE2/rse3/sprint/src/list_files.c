#include<common.h>
#include<functions.h>
#define BUFFER_SIZE 1024

// Function to execute the "ls" command and return the output
char* get_ls_output() {
    // Create a pipe
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("Pipe failed");
        return  NULL;
    }

    // Fork the process
    pid_t pid = fork();
    if (pid > 0) {
        // Parent process
        close(pipefd[1]);  // Close the write end of the pipe

        // Read the output of the ls command from the pipe
        static char buffer[BUFFER_SIZE]; // Static so it persists after the function returns
        ssize_t bytesRead = read(pipefd[0], buffer, sizeof(buffer) - 1);
        if (bytesRead > 0) {
            buffer[bytesRead] = '\0';  // Null-terminate the string
        }
        close(pipefd[0]);
        wait(NULL);  // Wait for the child process to finish

       return  buffer;  // Return the captured output
    } else if (pid == 0) {
        // Child process
        close(pipefd[0]);  // Close the unused read end of the pipe

        // Redirect stdout to the write end of the pipe
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);

        // Execute the ls command
        execl("/bin/ls", "ls","/home2/user46", (char *)NULL);
        perror("execl failed");  // If execl fails
        return NULL;
    } else {
        perror("fork failed");
        return NULL;
    }
}

