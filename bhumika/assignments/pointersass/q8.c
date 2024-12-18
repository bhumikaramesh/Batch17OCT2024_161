#include <stdio.h>
#include <string.h>
void read_displaystring(char arr[][10], int row)
{
    char *str = arr[row];
     printf("Alternate characters in the string '%s':\n", str);
    for (int i = 0; i < strlen(str); i += 2)  
    {
        printf("%c", str[i]);
    }
    printf("\n");
}
char *reverse(char arr[][10], int row)
{
    static char reversed[10];  
    char *str = arr[row];
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        reversed[i] = str[len - i - 1];
    }
    reversed[len] = '\0';  
    return reversed;  
}

int main()
{
    char arr[][10] = {"Word", "Excel", "PowerPoint", "Pdf", "Paint"};
    int row;
    printf("Enter the row index (0 to 4) to read and display every alternate character: ");
    scanf("%d", &row);
    
    if (row >= 0 && row < 5)  
    {
   
        read_displaystring(arr, row);
        char *reversed_str = reverse(arr, row);
        printf("Reversed string: %s\n", reversed_str);
    }
    else
    {
        printf("Invalid row index. Please enter a number between 0 and 4.\n");
    }
    
    return 0;
}

