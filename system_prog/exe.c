  #include<stdio.h>
  #include<stdlib.h>
  #include<sys\types.h>
 #include<unistd.h>
 #include<sys/wait.h>

 int main(int argc,char *argv[])
 {
 	char *temp[5];
	for(int i=0;i<5;i++)
	temp[i]=(char*)malloc(1024);
	strcpy(temp[0]=argv[1]);
	strcpy(temp[1]=argv[2]);
	strcpy(temp[2]=argv[3]);
	strcpy(temp[3]=argv[4]);
	temp[4]=(char*)0;
	exec(argv[1],temp);
return 0;
}

