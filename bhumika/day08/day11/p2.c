#include <stdio.h>


int main()
{
	char Name[5];
	int i;
	for(i=0;i<20;i++)
		scanf("%c",&Name[i]);

	Name[5-1] ='\0';

	for(i=0;i<20;i++)
		printf("\n%c=%d",Name[i],Name[i]);
	
	printf("\n\n");

	printf("\n%s\n",Name);
	puts(Name);
	printf("\n\n");
	return 0;
}