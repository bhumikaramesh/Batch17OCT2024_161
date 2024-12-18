#include <stdio.h>
#include <string.h>

char *my_strncat(char *dest, const char *src, size_t n) {
    char *dest_ptr = dest + strlen(dest); // Move to the end of dest string
    
    while (n-- && *src) {
        *dest_ptr++ = *src++; 
    }
    *dest_ptr = '\0'; 
    
    return dest;
}

int main() {
    char dest[100] = "Hello, ";
    char src[] = "World!";
    my_strncat(dest, src, 6);
    printf("Resulting string: %s\n", dest);
    
    return 0;
}

