#include <stdio.h>

int main() {
    int code;
    
    // Input designation code
    printf("Enter designation code: ");
    scanf("%d", &code);
    
    
    switch(code) {
        case 2:
            printf("Software Developer\n");
            break;
        case 3:
            printf("Senior Software Developer\n");
            break;
        case 4:
            printf("Team Lead\n");
            break;
        case 5:
            printf("Senior Team Lead\n");
            break;
        default:
            printf("Incorrect designation code\n");
    }
    
    return 0;
}
