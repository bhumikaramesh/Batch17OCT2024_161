#include<stdio.h>
register  int num1=10,num2=20;
int add(int num1,int num2);
int sub(int num1,int num2);
int mul(int num1,int num2);



int add(int num1,int num2){
	int a = num1+num2;
	return a;
}



int sub(int num1,int num2){
	if(num1>num2){
		int s = num1-num2;
		return s;
	}
	else{
		int s = num2-num1;
		return s;
	}
}


int mul(int num1,int num2){
	int m = num1*num2;
	return m;
}

int main(){

printf("%d",add(num1,num2));
printf("%d",sub(num1,num2));
printf("%d",mul(num1,num2));


}
