// A simple program calling a function in main()
#include <stdio.h>
#include <stdlib.h>


int simplelink(int lflag)
{
  int retval = 0;
  printf("\nENTER simplelink function");
  if (lflag == 0)
  {
    printf("\nlflag is equal to zero");
     retval = 0;
  }
  else
  {
    printf("\nlflag is different from zero");
    retval = 1;
  }
  printf("\nEXIT simplelink function");
  return retval;
}


int main()
{
  int flag = 10;
  int retval = 0;
  printf("\ngsimple before simplelink call: \n");
  retval = simplelink(flag);
  printf("\nreturn value from simplelink : %d \n", retval);
  return retval;
}
