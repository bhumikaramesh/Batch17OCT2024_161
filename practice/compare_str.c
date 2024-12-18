#include<stdio.h>
#include<string.h>
int main(){
	char str1[20];
	printf("Str1: ");
	scanf("%s",str1);
	char str2[20];
	printf("Str2: ");
	scanf("%s",str2);

	int flag=0;
	for(int i=0;str1[i]!='\0'|| str2[i]!='\0';i++){
		if(str1[i]!=str2[i]){
			flag=1;
			break;
		}
	}
	if(flag==1){
		printf("Not same");
	}
	else{
		printf("same");
	}
}
