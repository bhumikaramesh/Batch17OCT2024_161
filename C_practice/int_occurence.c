#include<stdio.h>
#define MAX 50
int main(){

	int str1[MAX],str2[MAX];
	int n1,n2,i;
	scanf("%d",&n1);
	printf("Array Size: %d", n1);
	for(i=0;i<n1;i++){
		scanf("%d",&str1[i]);
	}
	scanf("%d",&n2);
        printf("Array Size: %d", n2);
        for(i=0;i<n2;i++){
                scanf("%d",&str2[i]);
        }


	for(i=0;i<n1;i++){
		printf("%d",str1[i]);
	}
	
        for(i=0;i<n2;i++){
                printf("%d",str2[i]);
        }
}
