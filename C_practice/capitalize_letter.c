#include<stdio.h>
#include<string.h>
#define SIZE 20

char toUppercase(char ch){

        if(ch>=97 && ch<=122)
                ch -= 32;
        return ch;

}
int main(){
	char str[SIZE];
	fgets(str,sizeof(str),stdin);
	puts(str);
	str[0] = toUppercase(str[0]);
//	printf("%c",str[0]);
	int i =1;
	while(str[i] !='\0'){
		if(str[i]==' '){
			str[i+1] = toUppercase(str[i+1]);
			
		}
		i++;	
	}
	puts(str);	
}


