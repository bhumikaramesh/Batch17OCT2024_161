#include <stdio.h>


int main()
{
	char Name[5];
	int i;
	for(i=0;i<15;i++)
		scanf("%c",&Name[i]);

	Name[5-1] ='\0';

	for(i=0;i<15;i++)
		printf("\n%c",Name[i]);
	


	printf("\n%s\n",Name);
	puts(Name);
	printf("\n\n");
	return 0;
}
