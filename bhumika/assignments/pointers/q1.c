#include <stdio.h>

void display(int *ptr) {
    printf("Address of ptr: %p\n", (void*)ptr); 
    printf("Content pointed by ptr: %s\n", (char*)ptr); 
}

int main() {
  
    char arr[] = "hello hi";
    char *ptr = arr;
    printf("sizeof ptr: %zu, sizeof arr: %zu\n", sizeof(ptr), sizeof(arr));
    display(ptr); 
    
    return 0;
}

