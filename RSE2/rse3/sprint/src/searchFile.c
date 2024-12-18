/****************************************************************************
*   DATE : 13/12/2024
*   OWNER : GROUP-05
*	FILENAME:searchForFile.c
*	DESCRIPTION: Contains the code to search for a file in the filesystem 
*	            based on the provided file name. If the file exists, 
*	            it returns the absolute filepath; else returns NULL and 
*	            it logs an error and stores an appropriate message.
*****************************************************************************/

#include<common.h>
#include<functions.h>

char *searchForFile(char *filename) {
    const char *homeDir = "/home2/user46";  // Hardcoded home directory
    if (homeDir == NULL) {
		log_message("INFO","Searching For File");
        fprintf(stderr, "Home directory not found\n");
        return NULL;
    }

    // Use a pipe to capture the output of the find command
    int pipefd[2];
    if (pipe(pipefd) == -1) {
		log_message("FATAL","Pipe Creation Failed");
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
        char *resolvedPath = (char *)malloc(PATH_MAX*sizeof(char));
        if (resolvedPath == NULL) {
			log_message("FATAL","Memory allocation Failed");
            perror("malloc");
            return NULL;
        }

        ssize_t len = read(pipefd[0], resolvedPath, PATH_MAX - 1);
        if (len == -1) {
			log_message("FATAL", "Cannot get resolvedPath");
            perror("read");
            free(resolvedPath);
            return NULL;
        }

        resolvedPath[len] = '\0';  // Null-terminate the string

        close(pipefd[0]);
        // If the output is empty, the file was not found
        if (len == 0) {
            free(resolvedPath);
            return NULL;
        }

        // Close the read end of the pipe
		log_message("INFO","Searching for file is done");
        return resolvedPath;  // Return the resolved file path
    }
}
