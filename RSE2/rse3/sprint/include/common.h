#ifndef COMMON_H
#define COMMON_H

#include<pthread.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#define MAXBUFF 1024
#define PORTNO 5104
#define MAX_CLIENTS 10

typedef enum{
	LIST_FILES=1,
	SEARCH_FILE,
	SEARCH_STRING,
	DISPLAY_CONTENT,
	EXIT_PROGRAM
}MenuChoice;
#endif
