#include<common.h>
#include<functions.h>
char* get_time_str() {
    
    time_t now;
    time(&now);
 
    
    char *time_buf=(char *) malloc(64*sizeof(char));
    strftime(time_buf, 64, "%Y-%m-%d %H:%M:%S",localtime(&now) );
 
 
    return time_buf;
}
 
void log_message(char *level, char *message) {
	FILE *log_file = fopen("/home2/user46/sprint/data/logfile.txt", "a");
    if (log_file == NULL) {
        fprintf(stderr, "Error opening log file\n");
        exit(EXIT_FAILURE);
    }
 
    time_t now;
    time(&now);
//    char *time_str = get_time_str();
    char *time_buf=(char *) malloc(64*sizeof(char));
    strftime(time_buf, 64, "%Y-%m-%d %H:%M:%S",localtime(&now) );
    fprintf(log_file, "[%s] %s: %s\n", time_buf, level, message);
 
    free(time_buf);
    fclose(log_file);
}
