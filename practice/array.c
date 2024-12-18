#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int compare(const void *a,const void *b){
   return(*(int*)a-*(int* )b);
}
char* solve(int a_count, int* a){
  qsort(a,a_count,sizeof(int),compare);
   for(int i=0;i<a_count-1;i++){
       if(a[i+1]%a[i]!=0){
           return "No";
       }
   }
   return "Yes";
}
int main() {
   int a_count;
   scanf("%d", &a_count);
   int* a = (int*)malloc(a_count * sizeof(int)); 
   for (int i = 0; i < a_count; i++) {
       scanf("%d", &a[i]);
   }
 
   char* result = solve(a_count, a);
   printf("%s", result);
   free(a);
   return 0;
}
