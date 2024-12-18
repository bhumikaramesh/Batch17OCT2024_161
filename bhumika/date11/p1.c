#include<stdio.h>
#include<string.h>

int main()
{
int c1,c2,c3;
char temp[10]={'\0',};

char temp1[]={'2'};
char res[40]={'\0',};
printf("\n sizeof temp1=%d",sizeof(temp1));
c1=2;
c2=1;
c3=0;

//2*1=2
//c1*c2=c3

while(c2<11){
c3=c1*c2;
sprintf(temp,"%d*%d = %d ",c1,c2,c3);
strcpy(res,temp);

printf("\n%s\n",res);
c2++;
}
return 0;
 }
