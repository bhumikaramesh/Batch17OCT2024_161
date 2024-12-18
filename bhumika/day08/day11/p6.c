#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

	char s1[400],s2[20];
	char Names[10][20];
	int count=0,i;

	char *ptr=NULL;

	printf("\nEnter the Line with delimiter\n");
	scanf("%[^\n]s",s1);

	ptr = strtok(s1,",");
	count = 0;
	while(ptr != NULL){
		printf("\nptr = %s",ptr);
		strcpy(Names[count],ptr);
		count++;
		ptr = strtok(NULL,",");
	}

	printf("\nNames are\n");
	for(i=0;i<count;i++)
		printf("\n%s",Names[i]);

	/*
	printf("\nptr = %s",ptr);

	ptr = strtok(NULL,",");


    printf("\nptr = %s",ptr);


	ptr = strtok(NULL,",");
	if(ptr == NULL)
		printf("\nEnd of string");
	else
		printf("\nptr = %s",ptr);

	*/
	printf("\n\n");
	

	return 0;

}

