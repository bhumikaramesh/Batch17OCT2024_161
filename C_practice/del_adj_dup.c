#include<stdio.h>
#include<string.h>
#define MAX 50

char deleteDuplicate(char str[]){
	
	int i=0,j=0,k;
	char newstr[MAX];
	for(i=0;i<strlen(str);i++){
		k=i;
		if(str[k]-str[k+1]==0){
			while(str[k]-str[k+1]==0){
				k++;
			}
			i=k;
		}
		
		else{
			newstr[j]=str[i];
			j++;
		}

	}

	puts(newstr);
}

int main(){
	char str[MAX];
	printf("Enter string: ");
	fgets(str,sizeof(str),stdin);
	puts(str);

	deleteDuplicate(str);

	return 0;

}
