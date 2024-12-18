#include<stdio.h>
#include<string.h>
#define BUFF 1024

int main()
{
	int nTc=0;
	char date1[BUFF],date2[BUFF];
	int day1,day2,month1,month2,year1,year2;
	char *token=NULL;
	scanf("%d",&nTc);
	while(nTc--)
	{
	scanf("%s%s",date1,date2);

	token=strtok(date1,"/");
	month1=atoi(token);

	token=strtok(NULL,"/");
	day1=atoi(token);

	token=strtok(NULL,"/");
	year1=atoi(token);

//	printf("\n%d %d %d\n"day2,month2,year2);
	token=strtok(date2,"/");
	month2=atoi(token);
	
	token=strtok(NULL,"/");
	day2=atoi(token);
	
	token=strtok(NULL,"/");
	year2=atoi(token);




	if(year1<year2)
	{
	printf("E\n");
	}
	else if(year1==year2)
	{
	printf("S\n");
	}
	else if(year1>year2)
	{
	printf("L\n");
	}}
	else
	{
		if(month1<month2)
			{
			printf("E\n");
			}
			else if(month1==month2)
			{
			printf("S\n");
			}
			else if(month1>month2)
			{
			printf("S\n");
			}}
	else
	{


			if(day1<day2)
			{
			printf("E\n");
			}
			else if(day1==day2)
			{
			printf("S\n");
			}
			else if(day1>day2)
			{
			printf("S\n");
			}

}

