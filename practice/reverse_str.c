#include<stdio.h>
#include<string.h>
#define MAX 40
int main(){
	//USING POINTER
	char str[MAX];
	fgets(str,sizeof(str),stdin);
	

	char *begin_ptr, *end_ptr;
	
	begin_ptr = str;
	end_ptr = str + strlen(str)-1;

	while(begin_ptr < end_ptr){
		char ch = *begin_ptr;
		*begin_ptr = *end_ptr;
		*end_ptr = ch;
		
		begin_ptr++;
		end_ptr--;

	}

	puts(str);

	//WITHOUT POINTER
/*	char str[30];
	printf("Enter String: ");
	scanf("%s",str);
	printf("String: %s\n", str);
	
	int len = strlen(str);
	printf("length: %d\n",len);

	for(int i=0;i<len/2;i++){
		char temp = str[i];
		str[i] = str[len-1-i];
		str[len-1-i] = temp;
	}

	printf("Reverse String: %s\n",str);
*/
}

