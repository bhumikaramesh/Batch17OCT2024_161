#include<stdio.h>
#include<string.h>

#include<stdlib.h>
#define SIZE 100
int main(){

	int ch;
	
	char arr[SIZE];
	int i = 0;
	while((ch = getchar())!= EOF){
		//ch = getchar(ch);
		arr[i++]=ch;
	}
	puts(arr);

/*	ch = getchar();
	printf("%c\n",ch);
	printf("%d\n",ch);
	putchar(ch);
*/
}


