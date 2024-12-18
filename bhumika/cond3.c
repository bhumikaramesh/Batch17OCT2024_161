#include <stdio.h>

int main() {
    float test1, test2, test3, projectScore;

    // Input the scores for the four tests
    printf("Enter Test1 score: ");
    scanf("%f", &test1);

    printf("Enter Test2 score: ");
    scanf("%f", &test2);

    printf("Enter Test3 score: ");
    scanf("%f", &test3);

    printf("Enter Project score: ");
    scanf("%f", &projectScore);

    // Check eligibility using if-else
    if (test1 >= 75 && test2 >= 75 && test3 >= 70 && projectScore >= 75) {
        int result = 1;  // Eligible
        switch (result) {
            case 1:
                printf("Eligible for deployment\n");
                break;
        }
    } else {
        printf("Not eligible for deployment\n");
    }

    return 0;
}

