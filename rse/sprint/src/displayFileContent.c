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
     file = fopen(filename, "r");
     if (file == NULL) {
         perror("Error opening file");
         return "Error opening file";
     }


     while ((ch = fgetc(file)) != EOF) {
         if (i < sizeof(buf) - 1) {
             buf[i++] = ch;
         }
     }
     buf[i] = '\0';
     fclose(file);
     return buf;
 }

