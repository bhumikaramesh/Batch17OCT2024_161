#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

	char s1[20],s2[20];

	char d1[40],d2[40];

	char *ptr=NULL;


	scanf("%s%s",s1,s2);
	strcpy(d1,s1);
	printf("\nd1=%s",d1);
	strcat(d1,s2);
	printf("\nd1=%s",d1);
	printf("\n\n");
	return 0;
}