#include<common.h>
#include<functions.h>


char *searchForFile(char *filename) {
	
	char *resolvedPath = (char *)malloc(PATH_MAX);
    
    if (realpath(filename, resolvedPath) != NULL) {
        return resolvedPath; // Return the absolute path if file exists
    }
	else {
        free(resolvedPath); // Free memory if the file doesn't exist
        return NULL; // Return NULL if file does not exist
    }
}
