#include<stdio.h>
int main(){
//	int n;
//	scanf("%d",&n);
	char name[30];
	printf("Enter name: ");

	//using scanf
	//scanf("%s",name);
	
	// using gets function
	fgets(name);
	printf("%s\n",name);
	return 0;

}
