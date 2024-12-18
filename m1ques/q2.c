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




	
