#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *reverseStr(char *s)
{
	int i,l=strlen(s);
	char t;
	for(i=0;i<l/2;i++)
	{
		t=s[i];
		s[i]=s[l-i-1];
		s[l-i-1]=t;
	}
	return s;
}

char revStrPos(char *s,int a,int b)
{
	int i;
	char t;
	a--;
	b--;
	for(i=a;i<=b;i++)
	{
		t=s[i];
		s[i]=s[b-i];
		s[b-i]=t;
	}

	return s;
}
char *changestr(char *s,int a,int b,int val)
{
	char c=(char)val;
	int i;
	a--;
	b--;
	for(i=a;i<b;i++)
	{
		s[i]=c;
	}
	return s;
}

char *swapChars(char *s,int a,int b)
{
	char t;
	a--;
	b--;
	t=s[a];
	s[a]=s[b];
	s[b]=t;

	return s;
}


char *qSolve(char *s,int r,int c,int **quires)
{
	int si,ei,i;
	int qt;
	char *result=(char *)malloc(strlen(s)+1);
	strcpy(result,s);
	for(i=0;i<r;i++)
	{
		qt=quires[i][0];
		si=quires[i][1];
		ei=quires[i][2];
		val = quires[i][3];
		
		switch(qt)
		{
		case 1:
				reverseStr(result);
				break;
		case 2:
				revStrPos(result,si,ei);
				break;
		case 3:
				swapChars(result,si,ei);
				break;
		case 4:
				changestr(result,si,ei);
				break;
		default:
				break;
	}
	}
	}

	




















