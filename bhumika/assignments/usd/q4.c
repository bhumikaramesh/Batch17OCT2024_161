#include <stdio.h>

typedef struct Job {
    char name[32];          
    unsigned short ucount;  
    float salary;           
    int workerNo;           
    char *orgname;          
} Job;

int main() {
    Job myvar;  
    char *ptr = (char *)&myvar;  

    *(unsigned short *)(ptr + offsetof(Job, ucount)) = 0x0102; 

    *(unsigned short *)((char *)&myvar + 32) = 0x0102;  

    printf("ucount: 0x%04X\n", myvar.ucount);  

    return 0;
}

