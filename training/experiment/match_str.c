#include<stdio.h>
#include<string.h>
#define MAX 50
int main(){
	
	char str1[MAX];
	char str2[MAX];
	printf("Enter Str1: ");
       // scanf("%[^\n]s",str1);
//	scanf("%[^\n]s",str2);
//	puts(str1);
//	puts(str2);
	fgets(str1,sizeof(str1),stdin);
	puts(str1);
	printf("Enter Str2: ");

	fgets(str2,sizeof(str2),stdin);
	puts(str2);
	
	int count =0;
	for(int i=0;i< strlen(str1) && strlen(str2);i++ ){
		if(str1[i] == str2[i]){
			count++;
		}
		else
			break;
	
	}
	printf("%d  ", count);

}
