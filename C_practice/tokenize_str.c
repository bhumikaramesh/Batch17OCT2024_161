#include<stdio.h>
#include<string.h>
#define MAX 20
int main(){
	
	char str[MAX];
	fgets(str,sizeof(str),stdin);
	puts(str);
	int i=0;
	char *token = strtok(str," ");

	   

   	while (token != NULL) {
        	printf("%s\n", token);
       		 token = strtok(NULL, " ");
   	 }	
	return 0;
			
}
