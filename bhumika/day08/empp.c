 #include <stdio.h>
  #include <string.h>
  
   void getdetails(employee e[],int n)
   {
   int i;
   printf("enter the number of employees");
   for(i=0;i<n;i++);
   {
  printf("\nName:");
  scanf("%s",e[i].ename);
  printf("\nID:");
  scanf("%d",&e[i].eId);
  printf("\n Gender");
  scanf(" ");
  scanf("%c",&e[i].eGender);
 
  printf("\n salary");
  scanf("%c",&e[i].sal);
  }
  }
 
 void dispdetails(EMP e[],int n)
 {
 int i;
 printf("\n employee details are\n");
 for( i=0;i<n;i++){

 printf("\nID:%d"e[i].eID);
 printf("\nName:%s",e[i],e[i].eName);
 printf("\nGender:%s",e[i]

