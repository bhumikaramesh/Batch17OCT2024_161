// Online C compiler to run C program online
#include <stdio.h>
#include<string.h>

int main() 
{
    int n;
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++)
    {
        char input[1000];
        fgets(input,1000,stdin);
        input[strcspn(input,"\n")]='\0';
        char *a_pos=strchr(input,'a');
        int a_index=a_pos?(int)(a_pos-input):-1;
        char *is_pos=strstr(input,"is");
        int is_index=is_pos?(int)(is_pos-input):-1;
        int sum=a_index+is_index;
        printf("%d\n",sum);
    }
    return 0;
}
