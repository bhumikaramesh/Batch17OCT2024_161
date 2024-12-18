#include <stdio.h>
#include <string.h>

#define MAX 100
#define SUCCESS 0
#define FAILURE 1


int append(char *arr, const char *appendstr) {
  
    while (*arr) {
        arr++;  
    }    
    while (*appendstr) {
        *arr = *appendstr;  
        arr++;  
        appendstr++;  
    }
    
    *arr = '\0';  
    return SUCCESS; 
}
void display(char *ptr) {
    printf("\nAddress of ptr: %p\n", (void*)ptr);
    printf("Content pointed by ptr: %s\n", ptr);  
}

int main() {
    char arr[MAX] = "Learning C"; 
    char *ptr = arr;  
    char appendstr[] = " in my org"; 
    
    printf("Address of ptr before append: %p\n", (void*)ptr);  
    int ret = append(ptr, appendstr);

    printf("Address of ptr after append: %p\n", (void*)ptr);  
    
    if (ret == SUCCESS) {
        display(ptr);  
    } else {
        printf("Append failed\n");
    }
    
    return 0;
}

