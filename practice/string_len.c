#include<stdio.h>
#include<string.h>
int main(){

	char str[30];
	printf("Enter name: ");
	scanf("%s", str);
	printf("%s\n",str);
	printf("\n");
	int i=0,count = 0;
	while(str[i]!='\0'){
		count++;
		i++;
	}
	printf("Length : %d", count);

}	
