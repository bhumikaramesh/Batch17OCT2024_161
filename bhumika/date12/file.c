
   #include<stdio.h>
   #include<string.h>
   #include<stdlib.h>
  
   int main()
   {
       FILE *fd=NULL;
	   FILE *fd1=NULL;
      char ch='a';
	  char name[]="bhumika";
	 char rname[100];
	 int i;
     

     fd = fopen("test2.txt","w");
 
      if(*fd==NULL)
      {
          perror("fopen:");
         
          return 1;
 
      }
 
      printf("\n opened the file successfully %p\n",fd);
 
 	fd1=fopen("test3.txt","r");
 
 
 
      if(*fd==NULL)
      {
          perror("fopen:");
        return 1;
 
      }
 
 while((ch==fgetc(fd
   
