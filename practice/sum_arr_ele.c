#include<stdio.h>
#include<string.h>
int main(){
	int n,i;
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
//	printf("Length:%d\n",strlen(arr));
	int sum =0,*p;
	for(p=&arr[0];p<=&arr[n-1];p++){
		sum += *p;
	}
	printf("Sum is %d",sum);
/*	int sum =0;
	for(i=0;i<n;i++){
		sum += arr[i];
	}
	printf("%d",sum);
*/
}
