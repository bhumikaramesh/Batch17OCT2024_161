#include<stdio.h>
int main()
{
int itr=1;
looplabel:
	printf("\nitr= %d",itr);
	itr++;
	if(itr > 5)
		goto exitlabel:
	else
		goto looplabel:
exitlabel:
printf("\n\n");
return 0;
}
