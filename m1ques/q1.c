#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	int nbooks=3;
	int row=3;
	int col=1024;
	int i;
	char books[nbooks][row][col];

	strcpy(books[0][0],"Title");
	strcpy(books[0][1],"author");
	strcpy(books[0][2],"gener");

	printf("\nTITLE:%s",books[0][0]);
	printf("\nAuthor:%s",books[0][1]);
	printf("\nGener:%s",books[0][2]);

	printf("\n\n");

	strcpy(books[1][0],"C odyssey");
	strcpy(books[1][1],"vijaya mukhi");
	strcpy(books[1][2],"computer");

	printf("\nTITLE:%s",books[1][0]);
	printf("\nAuthor:%s",books[1][1]);
	printf("\nGener:%s",books[1][2]);
	
	printf("\n\n");
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	char ***Books=NULL;
	int i,j;
	int noBooks=2,row=3,col=50;


	//creating pointer to pointers which points
	// to different ptrs 
	Books = (char ***)malloc(sizeof(char **)*noBooks);

	for(i=0;i<noBooks;i++){
		//each pointer is pointing to different books
		//i.e  Books[0] => points to BA of ptr which 
		// points to different strings
		// allocate mem to have collections of strings
		// in each books representing title,auth,genre
		
		Books[i] = (char **)malloc(sizeof(char*)*row);
		for(j=0;j<row;j++)
		{
			//now allote mem for each strings
			Books[i][j] = (char *)malloc(sizeof(char)*col);
		}
	}


	for(i=0;i<noBooks;i++)
	{	
		printf("\nEnter, Title, Author,Genre of %d Book\n",(i+1));
			
		for(j=0;j<row;j++){
			scanf("%s",Books[i][j]);

		}
	}



	
	printf("\nBooks are\n");
	for(i=0;i<noBooks;i++)
	{	
			
		for(j=0;j<row;j++){
			printf(" %s ",Books[i][j]);

		}
		printf("\n");
	}
	printf("\n\n");

	return 0;
}#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	char ***Books=NULL;
	int i,j;
	int noBooks=2,row=3,col=50;


	//creating pointer to pointers which points
	// to different ptrs 
	Books = (char ***)malloc(sizeof(char **)*noBooks);

	for(i=0;i<noBooks;i++){
		//each pointer is pointing to different books
		//i.e  Books[0] => points to BA of ptr which 
		// points to different strings
		// allocate mem to have collections of strings
		// in each books representing title,auth,genre
		
		Books[i] = (char **)malloc(sizeof(char*)*row);
		for(j=0;j<row;j++)
		{
			//now allote mem for each strings
			Books[i][j] = (char *)malloc(sizeof(char)*col);
		}
	}


	for(i=0;i<noBooks;i++)
	{	
		printf("\nEnter, Title, Author,Genre of %d Book\n",(i+1));
			
		for(j=0;j<row;j++){
			scanf("%s",Books[i][j]);

		}
	}



	
	printf("\nBooks are\n");
	for(i=0;i<noBooks;i++)
	{	
			
		for(j=0;j<row;j++){
			printf(" %s ",Books[i][j]);

		}
		printf("\n");
	}
	printf("\n\n");

	return 0;
}


	char **books1=(char **)(malloc(10*sizeof(char*)));
	for(i=0;i<10;i++)
	scanf("%s",&books1)
	
	char **author=(char **)(malloc(10*sizeof(;
return 0;
}

