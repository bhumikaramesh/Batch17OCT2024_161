#include <stdio.h>
#include <stdlib.h>

#define True 1


int bubSort(int *, int);
int selSort(int *, int);
int insort(int *,int);
int swapEle(int *, int *);

void display(int *, int);

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

	

	printf("\nBefore Sorting\n");
	display(a,count);
	//bubSort(a,count);
	selSort(a,count);
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
		for(j=0;j<CAP-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swapEle(&arr[j],&arr[j+1]);
				
			}
		}
	}
	return True;
}



int selSort(int *arr, int CAP)
{
	int i,j;
	int min_i;
	int flag=0;
	for(i=0;i<CAP-1;i++)
	{
		min_i = i;
		flag = 0;
		for(j=i+1;j<CAP-1;j++)
		{
			if(arr[min_i]>arr[j])
			{
				min_i = j;
				flag = 1;
			}
		}
		if(flag == 1)
			swapEle(&arr[i],&arr[min_i]);
	}
	return True;
}

int insertionSort(int *arr,int CAP)
{
	int i,j;
	int key;
	int flag=0;
	for(i=1;i<CAP-1;i++)
	{

	j=j-1;
	flag=0;
	while(j>=0 && key<arr[j])
	{
	arr[j+1]=arr[j];
	j-=1;
	}
	arr[j+1]=key;
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
	
	// printf("\n%d %d",*t1,*t2);
	temp = *t1;
	*t1 = *t2;
	*t2 = temp;
}
