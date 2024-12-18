/***************************************************************************
*   DATE:13/12/2024
*   OWNER: Group-05
*   FILENAME :displayFileContents.c
*   DESCRIPTION: Contains the code to read the contents of a file from the
*                given file path and store them in  buffer and return the buffer
*                otherwise, an error message is stored in the buffer.
*                Logs important events such as file existence and errors.
*****************************************************************************/
#include<common.h>
#include<functions.h>

char *displayFileContents(char *filename)
{
       FILE *file;
       static char buf[1024];
       int ch;
       int i=0;

     memset(buf, 0, sizeof(buf));
     printf("\n %s",filename);
//	 snprintf(buffer,sizeof(buffer),"/home2/user46/%s",filename);
	 log_message("INFO","Opening  File");
	 file = fopen(filename, "r");
     if (file == NULL) {
	 	 log_message("FATAL","Error Opening File");
         perror("Error opening file");
         return "Error opening file";
     }

	
	 log_message("INFO","Reading contents of File");
     while ((ch = fgetc(file)) != EOF) {
         if (i < sizeof(buf) - 1) {
             buf[i++] = ch;
         }
     }
     buf[i] = '\0';
     fclose(file);
     return buf;
 }

