#include <stdio.h>

typedef union Job {
    char name[32];          
    unsigned short ucount;  
    float salary;           
    int workerNo;           
    char *orgname;          
} Job;

int main() {
    Job uarr[10];
	  uarr[0].salary = 5000.50;
	  printf("Salary: %.2f\n", uarr[0].salary);
	  uarr[0].workerNo = 1001;
	  printf("Worker No: %d\n", uarr[0].workerNo);
	 printf("Salary (after workerNo): %.2f\n", uarr[0].salary);
	 return 0;
}
 

