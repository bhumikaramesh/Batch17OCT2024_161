#include<stdio.h>
#include<string.h>
int main(){
	char str1[30];
	printf("Enter str1: ");
	scanf("%s",str1);
	printf("Str1: %s \n",str1);

	char str2[30];
	printf("Enter str2: ");
	scanf("%s",str2);
	printf("Str2: %s \n",str2);

	int len1 = strlen(str1);
	int len2 = strlen(str2);

	for(int i =0;i<=len2;i++){
		str1[len1+i] = str2[i];
	}
	printf("%s ",str1);
}
