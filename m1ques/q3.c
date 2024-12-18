#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_LEN 100

void bubbleSort(char *books[MAX_BOOKS][3], int n) {
    int i, j;
    char *temp[3];

    
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (strcmp(books[j][2], books[j+1][2]) > 0) {
                
                for (int k = 0; k < 3; k++) {
                    temp[k] = books[j][k];
                    books[j][k] = books[j+1][k];
                    books[j+1][k] = temp[k];
                }
            }
        }
    }
}

int main() {
    int N;
    char buffer[MAX_LEN];
    
    scanf("%d", &N);
    getchar();  

    char *books[MAX_BOOKS][3];

    for (int i = 0; i < N; i++) {
        fgets(buffer, sizeof(buffer), stdin);
        
        books[i][0] = (char *)malloc(MAX_LEN * sizeof(char));
        books[i][1] = (char *)malloc(MAX_LEN * sizeof(char));
        books[i][2] = (char *)malloc(MAX_LEN * sizeof(char));
        
        sscanf(buffer, "%[^,],%[^,],%[^\n]", books[i][0], books[i][1], books[i][2]);
    }

    bubbleSort(books, N);

    for (int i = 0; i < N; i++) {
        printf("%s\n", books[i][0]);
    }

    for (int i = 0; i < N; i++) {
        free(books[i][0]);
        free(books[i][1]);
        free(books[i][2]);
    }

    return 0;
}

