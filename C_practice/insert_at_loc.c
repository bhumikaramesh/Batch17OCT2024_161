#include<stdio.h>
#include<string.h>
#define MAX 50
//
void insert_at_pos(char mainStr[],char substr[],int pos){
	int mainLen = strlen(mainStr);
	int subLength = strlen(substr);

	int newLen = mainLen + subLength - 1;
//	printf("%d",newLen);

	char newStr[newLen];

	int i=0;
	for(i=0;i<pos-1;i++){
		newStr[i] = mainStr[i]; 	
	}	

	for(i=0;i<subLength-1;i++){
		newStr[i+pos-1] = substr[i];
	}
	for(i=0;i<mainLen-pos+1;i++){
		newStr[i+pos+subLength-2] = mainStr[pos-1+i];
	}
	


	puts(newStr);


}
int main(){
	char mainStr[MAX],substr[MAX];
	printf("Enter string1: ");
	fgets(mainStr,sizeof(mainStr),stdin);
	//printf("Size : %ld\n",sizeof(str1));
	printf("Enter string2: ");
        fgets(substr,sizeof(substr),stdin);
	int pos;
	printf("Enter loctaion: ");
	scanf("%d",&pos);
	insert_at_pos(mainStr,substr,pos);
	

}
