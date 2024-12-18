#include <stdio.h>

int main() {
    int N, num;
    int positive=0, negative=0, zero=0;
    
 
    printf("Enter the number: ");
    scanf("%d",&N);
    
    
    for (int i=1; i<=N; i++) {
        printf("Enter integer %d: ", i);
        scanf("%d",&num);

		 if (num > 0) {
            positive++;
        } else if (num < 0) {
            negative++;
        } else {
            zero++;
        }
    }

    // Display the results
    printf("\nNumber of positive integers: %d\n", positive);
    printf("Number of negative integers: %d\n", negative);
    printf("Number of zero integers: %d\n", zero);

    return 0;
}
       
   

