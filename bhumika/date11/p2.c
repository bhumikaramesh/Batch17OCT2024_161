#include<stdio.h>

int main()
{
	char lines[]="Amit,Kumar,Ravi";
	char names[10][20];
	int row,colum;
	int count=0;

	char *ptr =NULL;

	ptr=lines;
	count=0;

	while(*ptr!='\0')
		{
		putchar(*ptr);
		ptr++;
		}
		
	ptr = lines;

	while(*ptr!='\0')
	{
	if(*ptr == ',')
		break;
		ptr++;
	}

	ptr = lines;
	row=0;
	column=0;
	while(*ptr !='\0')
	{
	if(*ptr==',')
	names[row][column]=*ptr;
	ptr++;
	col++


