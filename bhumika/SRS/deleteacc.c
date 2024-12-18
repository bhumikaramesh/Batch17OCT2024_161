FILE *Afile;

void deleteAccount(Account Acc)
{
int accNum,found=0, i,j;
printf("enter Account number:");
scanf("%d",&accNum);

for(i=0;i<accountCount;i++)
{
if(accounts[i].accNum==accNum)
{
for(j=i;j<accountCount-1;j++)
{
accounts[j]=accounts[j+1];
}
accountCount--;
printf("account deleted succesfully");
found=1;
break;
}
}
if(!found)
{
printf("account not found.\n");
}
fclose(Afile);
return 0;
}

