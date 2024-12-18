#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{

	char s1[20],s2[20];

	char d1[40],d2[40];

	char *ptr = NULL;
	int ret=0;

	scanf("%s%s",s1,s2);
	printf("\ns1=%s\ts2=%s",s1,s2);

	//ptr = (char *)malloc(strlen(s1)+1);
	/*
	ret = strcmp(s1,s2);

	printf("\nRet = %d",ret);
	*/

	ptr = strcpy(d1,s1);
	// printf("\nd1=%s",d1);

	printf("\nptr = %s",ptr);

	printf("\nAddress of d1=%u\nAddress of ptr=%u\n",&d1[0], ptr);


	printf("\n\n");

	return 0;
}