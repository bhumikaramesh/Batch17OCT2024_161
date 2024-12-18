#include<stdio.h>

FILE A*file

void updateAccount(Account Acc)
{
	int accNum,found=0;
	int i;
	printf("enter account number");
	scanf("%d",&accNum);

	for(i=0;i<accNum;i++)
	{
	if(accounts[i].accNum==accNum)
	{
	printf("enter new address");
	scanf("%d[^\n]s",accountNumber[i].address);
	printf("enter new contact number");
	scanf("%s,account[i].contactNumber");
	printf("account updated successfully\n");
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


