#include<stdio.h>
#include<string.h>

int string(const char*A,const char *B,const char *C)
{
    int freq[26]={0};
    for(int i=0;C[i]!='\0';i++)
    {
        freq[C[i]-'A']++;
    }
    for(int i=0;A[i]!='\0';i++)
    {
        if(--freq[A[i]-'A']<0)
        {
            return 0;
        }
    }
    for(int i=0;B[i]!='\0';i++)
    {
        if(--freq[B[i]-'A']<0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char A[101],B[101],C[101];
    scanf("%s %s %s",A,B,C);
    if(string(A,B,C))
    {
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
    return 0;
}
