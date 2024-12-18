#include<stdio.h>
#include<string.h>
int main(){
	
	char name[30];
	printf("Enter name: ");
	scanf("%s",name);
	printf("%s",name);

	int i=0,count=0;
	while(name[i]!='\0'){
		count++;
		i++;
	}
	printf("%d",count);

	
}
