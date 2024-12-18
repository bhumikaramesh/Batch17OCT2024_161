#include<stdio.h>

int Binarysearch(int arr[],int x,int low,int high)
{
int mid;
mid=(low+high)/2;
if(x==arr[mid])
{
} return mid; 
 else if(x>arr[mid])

 return BinarySearch(arr, x, mid + 1, high);

else
	return BinarySearch(arr, x, low,mid-1);
}
return -1;
}
int main()
{
int arr[]={1,2,3,4,5,6,7};
int length=sizeof(arr)/sizeof(arr[0]);
 int x = 4;
  int result = BinarySearch(arr, x, 0,length - 1);
  if (result == -1)
    printf("Not found");
  else
    printf("Element is found at index %d", result);
  return 0;
}
