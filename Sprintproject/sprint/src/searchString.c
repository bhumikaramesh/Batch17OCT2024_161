#include<common.h>
#include<functions.h>


char* searchForString(const char* pattern) {
    static char buffer[MAXBUFF]; // Static buffer to persist after function returns

    // Create a pipe to capture the output of grep
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("Pipe failed");
        return NULL;
    }

    // Fork the process
    pid_t pid = fork();
    if (pid > 0) {
        // Parent process
        close(pipefd[1]);  // Close the write end of the pipe

        // Read the output of the grep command from the pipe
        ssize_t bytesRead = read(pipefd[0], buffer, sizeof(buffer) - 1);
        buffer[bytesRead] = '\0';  // Null-terminate the string
        close(pipefd[0]);

        wait(NULL);  // Wait for the child process to finish

        // Return the output captured from the pipe
        return buffer;
    } else if (pid == 0) {
        // Child process
        close(pipefd[0]);  // Close the unused read end of the pipe

        // Redirect the output to the pipe
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);

        // Execute the grep command
   //  execlp("/bin/grep","grep","-c", "grep -l '"pattern"' *", (char *)NULL);  // Search pattern in all files
        char command[MAXBUFF];
        snprintf(command, sizeof(command), "grep -l -R '%s' /home2/user46/*", pattern);
        execlp("sh", "sh", "-c", command, (char *)NULL);
        perror("execlp failed");  // If execl fails
//        snprintf(buffer,sizeof(buffer),"grep -rl '%s' .",pattern);
        return buffer;
    exit(EXIT_FAILURE);
         } 
		else {
        perror("fork failed");
        return NULL;
    }
}






