#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

	char s1[40],s2[20];

	char d1[40],d2[40];

	char *ptr=NULL;

	printf("\nEnter the Main String: \n");
	scanf("%[^\n]s",s1);
	printf("\nEnter the Sub String: ");
	scanf("%s",s2);
	ptr = strstr(s1,s2);
	if(ptr == NULL)
		printf("\nSub String %s not found\n",s2);
	else
	{
		printf("\nBase Address of s1=%u\n",&s1[0]);
		printf("\nSub String Found %s at %u",ptr,&ptr[0]);
	}
	
	printf("\n\n");
	return 0;
}