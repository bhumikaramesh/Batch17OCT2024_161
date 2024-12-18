#include<stdio.h>
#define MAX 50
int main(){
	char str[MAX];
	FILE * fp = fopen("hello.c","w+");
	//fputc('c',fp);
	//fgetc(fp);
	//fseek(fp);
	for(int i=0;i!=EOF;i++){
		str = fgetc(fp);
		fprintf(fp,str);
	}
	fclose(fp);
	
	return 0;

}

