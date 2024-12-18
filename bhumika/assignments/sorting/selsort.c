#include <stdio.h>
#include <stdlib.h>

#define True 1


int bubSort(int *, int);

int swapEle(int *, int *);

void display(int *, int);
int selsort(int *,int);
int main(int argc, char *argv[])
{
	int *a=NULL;

	int key;
	int i,count;


	if(argc<3){
		printf("\nEnter atleast 1 element\n\n");
		return EXIT_FAILURE;
	}

	a = (int *)malloc(sizeof(int)*(argc-1));
	for(i=1,count=0;i<argc;i++,count++)
		a[count] = atoi(argv[i]);
		a[count]=atoi(

	

	printf("\nBefore Sorting\n");
	display(a,count);
	bubSort(a,count);
	printf("\nAfter Sorting\n");
	display(a,count);

	printf("\n\n");
	return 0;
}

int bubSort(int *arr, int CAP)
{
	int i,j;
	int t;
	for(i=0;i<CAP-1;i++)
	{
		for(j=0;i<CAP-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				//	swapEle(&arr[j],&arr[j+1]);
				t = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = t;
			}
		}
	}
	return True;
}
int selsort(int *arr,int CAP)
{
	int i ,j;
	int minindex=i;
	for(i=0;i<=CAP-1;i++)

	{
	minindex=i;
	for(j=j+1;j<CAP-1;j++)
	{
		if(arr([minindex-1]<arr[j]))
		{
		minindex=j;
		flag=1;
		}
		}
		if(flag==1)
			swapEle(&arr[i],&arr[minindex]

}


return True;
}


void display(int *arr, int CAP)
{
	int i;
	printf("\nList is\n\n");
	for(i=0;i<CAP;i++)
		printf("%d ",arr[i]);
	printf("\n\n");
}

int swapEle(int *t1, int *t2)
{
	int temp;
	printf("\n%d\t%d\n",*t1,*t2);
	temp = *t1;
	*t1 = *t2;
	*t2 = temp;
}
