#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 80
int write(FILE *fptr, char *line)
{
    if (fptr == NULL || line == NULL) {
        return -1;
    }
    fprintf(fptr, "%s\n", line);
    return 0;
}
int read(FILE *fptr, char *linebuf) {
    if (fptr == NULL || linebuf == NULL) {
        return -1;
    }
    if (fgets(linebuf, MAX_LINE_LENGTH, fptr) == NULL) {
        return -1;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc != 3) { 
        printf("Please provide exactly 2 lines of text as command line arguments.\n");
        return -1;
    }
    char line1[MAX_LINE_LENGTH];
    char line2[MAX_LINE_LENGTH];
    strncpy(line1, argv[1], MAX_LINE_LENGTH);
    strncpy(line2, argv[2], MAX_LINE_LENGTH);
    FILE *fout = fopen("fout.txt", "w");
    if (fout == NULL) {
        printf("Error opening file for writing.\n");
        return -1;
    }
    write(fout, line1);
    write(fout, line2);
    fclose(fout);
    fout = fopen("fout.txt", "r");
    if (fout == NULL) {
        printf("Error opening file for reading.\n");
        return -1;
    }
    char readbuf[MAX_LINE_LENGTH];
    while (read(fout, readbuf) == 0) {
        printf("Read from file: %s", readbuf);
    }
    fclose(fout);

    return 0;
}

