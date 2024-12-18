#include <stdio.h>

#define ROWS 3
#define COLS 3
int init(char arr[ROWS][COLS])
{    char temp[ROWS][COLS] = 

{
        {'A', 'B', 'C'},
        {'D', 'E', 'F'},
        {'G', 'H', 'I'}
};
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            arr[i][j] = temp[i][j];
        }
    }
    return 0;
}
int search_update(char arr[ROWS][COLS], char search, char update)
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (arr[i][j] == search) {
                arr[i][j] = update; 
                return 0;
            }
        }
    }
    return 1; 
}
void display(char arr[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char arr[ROWS][COLS];  
    init(arr);
    printf("Initial array:\n");
    display(arr);
    char search = 'D';
    char update = 'X';
    
    int result = search_update(arr, search, update);
    
    if (result == 0) {
        printf("\nArray after updating '%c' to '%c':\n", search, update);
        display(arr);
    } else {
        printf("\nElement '%c' not found in the array.\n", search);
    }
    
    return 0;
}

