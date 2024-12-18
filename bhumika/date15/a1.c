#include<stdio.h>

int main()

{
	char str[100];
	char ch;
	int count=0;
	int i;

	printf("enter a string");
	fgets(str,sizeof(str),stdin);

	printf("enter the character to find");
	scanf("%c",&ch);

for(i=0;str[i]!='\0';++i)
{
	if(ch==str[i])
	++count;
}
	printf("frequency of occurance of %c= %d\n",ch,count);
	return 0;
}

