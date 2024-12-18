#include<stdio.h>
#include<string.h>
int length_of_string(char str[]);
void reverse(char str[],int len);
int main(){
	char str[30];
	printf("Enter String: ");
	scanf("%s",str);
	printf("String: %s\n", str);

	int len = length_of_string(str);
	printf("Length: %d\n",len);
	int flag =0;
	for(int i=0;i<len;i++){
		if(str[i]!=str[len-i-1]){
			flag = 1;
			break;
		}
	}
	if(flag){
		printf("Not Palindrome");
	}
	else{
		printf("Palindrome");
	}

}

void reverse(char str[],int len){
	int i;
	for(i=0;i<len/2;i++){
		int temp = str[i];
		str[i] = str[len-1-i];
		str[len-1-i] = temp;	
	}
}
int length_of_string(char str[]){
	int i = 0, size = 0;
	while(str[i]!='\0'){
		size++;
		i++;
	}
	return size;

}
