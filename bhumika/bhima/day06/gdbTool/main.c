#include <stdio.h>

int function1(int val)
{
	int j;
	for(j=0;j<val;j++)
		printf("\n%d",j);
	return j;
}

int main()
{
	int i=0;
	int x=2;
	int y=4;

	for(i=0;i<3;i++)
	{
		printf("\nprod=%d\n",(x*y));
		y++;
	}

	i = function1(y);

	printf("\ni=%d\n\n",i);


	return 0;
}

