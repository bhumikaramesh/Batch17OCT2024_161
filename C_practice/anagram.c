/*#include<stdio.h>
#include<string.h>
#define SIZE 30

void sorting_str(char str[]){
	int len1 = strlen(str)-1;
	printf("%d",len1);
	for(int i=0;i<len1-1;i++){
		for(int j=0;j<len1-1-i;j++){
			if(str[j]>str[j+1]){
				int temp = str[j];
				str[j] = str[j+1];
				str[j+1] = temp;
			}
		}
	}
}
int main(){
        char str1[30],str2[30];
        printf("Enter String1: ");
        fgets(str1,sizeof(str1),stdin);
        printf("%s",str1);

//      printf("Enterr String2: ");
//      fgets(str2,sizeof(str2),stdin);
//      puts(str2);
        sorting_str(str1);
        puts(str1);

}
*/
#include<stdio.h>
#include<string.h>
#define MAX 100 
void sort_anagram(char string[])
{
        int i,j,length,temp;
        length = strlen(string)-1;
        for(i = 0; i<length-1;i++)
        {
                for(j = 0; j<length-1-i; j++)
                {
                        if (string[j]>string[j+1])
                        {
                                temp = string[j];
                                string[j] = string[j+1];
                                string[j+1] = temp;
                        }
                }
        }
}
 
 
int main()
{
        char string1[MAX], string2[MAX];
        printf("Enter first string: ");
        fgets(string1, sizeof(string1), stdin);
        printf("Enter second string: ");
        fgets(string2, sizeof(string2), stdin);
        if(strlen(string1)==strlen(string2)){
		sort_anagram(string1);
    		sort_anagram(string2);
	}
        if(strcmp(string1, string2) == 0)
		printf("Strings are ANAGRAM ");
      	else
                printf("Strings are NOT anagram ");
 
      	 return 0;
 
}
