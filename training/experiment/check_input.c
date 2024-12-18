#include<stdio.h>
#include<string.h>
 
int toLower(char ch){
	if(ch >= 'A' && ch <= 'Z')
		ch += 'a'-'A';
	return ch;

}
int isDigit(char ch){
//	int flag=0;
	if(ch >= '0' && ch <= '9')
		return 1;
	return 0;
}

int alphabet(char ch){
	//int flag=0;
	
	ch = toLower(ch);
	
	if(ch >='a' && ch <='z')
		return 1;
	return 0;

}

int isSpecialChar(char ch){

	if(ch =='!'||ch =='@'||ch =='#'||ch =='$'||ch =='%'||ch =='^'||ch =='&'||ch =='*')
		return 1;
	return 0;
}


int check_input_type(char ch){
	if(isDigit(ch))
		return 1;
	else if(alphabet(ch))
		return 2;
	else if(isSpecialChar(ch))
		return 3;

}



int main(){
	char ch;
	scanf("%c",&ch);
	int flag = check_input_type(ch);
	if(flag==1)
		printf("Digit");
	if(flag==2)
		printf("Alphabet");
	if(flag==3)
		printf("Special Character");
	else
		printf("others");
	return 0;

}
	

