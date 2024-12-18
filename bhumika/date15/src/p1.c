#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define BUFF 1024
#define OR ||


int main(int argc, char *argv[])

{
	FILE *fp=NULL;

	int noLine;
	system("wc -l ../data/db.txt");

	fp = fopen("../data/db.txt", "r");


	

	fscanf(fp,"%d",&noLine);

	printf("\nLines = %d\n\n",noLine);

	fclose(fp);

	return 0;


}
