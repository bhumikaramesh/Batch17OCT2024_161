#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 80

int merge_files(const char *int_file, const char *str_file, const char *out_file)
{
    FILE *f1 = fopen(int_file, "r");
    FILE *f2 = fopen(str_file, "r");
    FILE *fout = fopen(out_file, "w");

    if (f1 == NULL || f2 == NULL || fout == NULL) {
        printf("Error opening files.\n");
        return -1;
    }

    int num;
    char str[MAX_LINE_LENGTH];

    while (fscanf(f1, "%d", &num) != EOF && fgets(str, MAX_LINE_LENGTH, f2) != NULL) {
        fprintf(fout, "%d%s", num, str);
    }

    fclose(f1);
    fclose(f2);
    fclose(fout);

    return 0;
}

void display(const char *file)
{
    FILE *f = fopen(file, "r");
    if (f == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, f)) {
        printf("%s", line);
    }

    fclose(f);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Please provide exactly 3 filenames as command line arguments.\n");
        return -1;
    }

    const char *int_file = argv[1];
    const char *str_file = argv[2];
    const char *out_file = argv[3];
    if (merge_files(int_file, str_file, out_file) != 0) {
        return -1;
    }
    printf("Merged file content:\n");
    display(out_file);

    return 0;
}

