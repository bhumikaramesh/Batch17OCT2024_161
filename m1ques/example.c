#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	int nbooks=3;
	int row = 3;
	int col = 1024; // bytes
	char books[nbooks][row][col];

	char book1[3][50];
	char book2[3][50];
	char book3[3][50];

	strcpy(book1[0],"C odesey1"); //first book
	strcpy(book1[1],"Vijaya Mukhi1");
	strcpy(book1[2],"Computer1");

	printf("\nTitle: %s",book1[0]);
	printf("\nAuthor: %s",book1[1]);
	printf("\nGener: %s",book1[2]);

	strcpy(book2[0],"C odesey2"); //first book
	strcpy(book2[1],"Vijaya Mukhi2");
	strcpy(book2[2],"Computer2");

	printf("\nTitle: %s",book2[0]);
	printf("\nAuthor: %s",book2[1]);
	printf("\nGener: %s",book2[2]);

	strcpy(book3[0],"C odesey3"); //first book
	strcpy(book3[1],"Vijaya Mukhi3");
	strcpy(book3[2],"Computer3");

	printf("\nTitle: %s",book3[0]);
	printf("\nAuthor: %s",book3[1]);
	printf("\nGener: %s",book3[2]);


	
	printf("\nBook1=%p",book1);
	printf("\nBook2=%p",book2);
	printf("\nBook3=%p",book3);


	char **ptr1 = book1[0];
	char **ptr2=book1[1];
	char **ptr3=book1[2];
	printf("\nContents of ptr1=%p\nits own Add=%p",ptr1,&ptr1);
	printf("\n%s\t%s",book1[0],ptr1);
	printf("\n%s\t%s\n",ptr2,ptr3);
	// char ***ptr1 = &books[0];
	// printf("\nAddress of ptr=%p\nits own Add=%p",ptr1,&ptr1);
	
	// char ***ptr2 = &books[1];
	// printf("\nAddress of ptr=%p\nits own Add=%p",ptr2,&ptr2);
	
	// char ***ptr3 = &books[2];
	// printf("\nAddress of ptr=%p\nits own Add=%p",ptr3,&ptr3);
	
	// // printf("\ncontents of ptr=%s",**ptr);

	printf("\n\n");
	return 0;
	
	
	

}
