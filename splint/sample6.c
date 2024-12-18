
#include <stdio.h>

#define ROWS    4
#define COLS    4

int pows[ ROWS ][ COLS ] = { { 1000, 1000, 1000, 1000 },
                 {  900,  500,  400,  100 },
                 {   90,   50,   40,   10 },
                 {    9,    5,    4,    1 } };

char *roms[ ROWS ][ COLS ] = { {  "m",  "m",  "m", "m" },
                   { "cm",  "d", "cd", "c" },
                   { "xc",  "l", "xl", "x" },
                   { "ix",  "v", "iv", "i" } };

int checkvalue( int value )
{
  if ( value < 1 || value > 9999 ) {
     fprintf( stderr, "Use numbers in the range 1 .. 9999\n");
     exit( 0 );
  }
}

int to_roman( int decimal, char * roman )
{
 /*
  * Splint catches the fact that the variable rom_pos is never used
  * You can fix this problem by deleting the following declaration
  */
  int rom_pos = 0;      /* Current character position */
  int power;            /* Current power of ten */
  int indx;         /* Indexes thru values to subtract */
  
  roman[ 0 ] = '\0';

  for ( power = 0; power < ROWS; power++ )
    for ( indx = 0; indx < COLS; indx++ )
    while ( decimal >= pows[ power ][ indx ] ) {
       strcat( roman, roms[ power ][ indx ] );
       decimal -= pows[ power ][ indx ];
    }
}

int main( int argc, char *argv[] )
{
  int low;          /* Starting number from command line */
  int high;         /* Ending number from command line */
  char roman[ 25 ];     /* Converted Roman number */

  if ( argc < 2 ) {
     printf( "Usage: roman  decimal_number\n" );
     exit( 0 );
  }

  low = atoi( argv[ 1 ] );
  high = low;
  checkvalue( low );
  if ( argc > 2 ) {
     high = atoi( argv[ 2 ] );
     checkvalue( high );
     if ( low > high ) {
    fprintf( stderr, "Lower number must be less than the higher number\n" );
    exit( 0 );
     }
  }
  else
    low = 1;            /* Low side is 1 if only one argument */

  for ( ; low <= high; low++ )  {
    to_roman( low, roman );
    fprintf( stdout, "%d %s\n", low, roman );
  }
 /*
  * Splint catches the fact that upon normal termination, no return value
  * is specified by the main program.  You can fix this error by
  * including an ending     return( 0 );    or    exit( 0 );   statement.
  */
}

