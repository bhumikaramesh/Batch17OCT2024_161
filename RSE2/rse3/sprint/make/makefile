CC = gcc
CFLAGS = -Wall -g -I../include
TFLAGS = -pthread  # Declare pthread flags here

SRC_DIR = ../src
OBJ_DIR = ../obj
BIN_DIR = ../bin
INCLUDE_DIR = ../include
REPORTS_DIR=../reports
SRC_FILES = $(SRC_DIR)/client1.c $(SRC_DIR)/displayFileContent.c $(SRC_DIR)/list_files.c $(SRC_DIR)/searchString.c $(SRC_DIR)/server1.c
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
EXECUTABLES = $(BIN_DIR)/client1 $(BIN_DIR)/server1

all: $(EXECUTABLES)

$(BIN_DIR)/client1: $(OBJ_DIR)/client1.o
	$(CC) $(CFLAGS) $(TFLAGS) -o $(BIN_DIR)/client1 $(OBJ_DIR)/client1.o  

$(BIN_DIR)/server1: $(OBJ_DIR)/server1.o $(OBJ_DIR)/displayFileContent.o $(OBJ_DIR)/searchString.o $(OBJ_DIR)/list_files.o $(OBJ_DIR)/searchFile.o $(OBJ_DIR)/log.o
	$(CC) $(CFLAGS) $(TFLAGS) -o $(BIN_DIR)/server1 $(OBJ_DIR)/server1.o $(OBJ_DIR)/displayFileContent.o $(OBJ_DIR)/searchString.o $(OBJ_DIR)/list_files.o $(OBJ_DIR)/searchFile.o $(OBJ_DIR)/log.o 

$(OBJ_DIR)/client1.o: $(SRC_DIR)/client1.c $(INCLUDE_DIR)/common.h
	$(CC) $(CFLAGS) $(TFLAGS) -c $(SRC_DIR)/client1.c -o $(OBJ_DIR)/client1.o  

$(OBJ_DIR)/displayFileContent.o: $(SRC_DIR)/displayFileContent.c $(INCLUDE_DIR)/common.h $(INCLUDE_DIR)/functions.h
	$(CC) $(CFLAGS) $(TFLAGS) -c $(SRC_DIR)/displayFileContent.c -o $(OBJ_DIR)/displayFileContent.o  

$(OBJ_DIR)/list_files.o: $(SRC_DIR)/list_files.c $(INCLUDE_DIR)/common.h $(INCLUDE_DIR)/functions.h
	$(CC) $(CFLAGS) $(TFLAGS) -c $(SRC_DIR)/list_files.c -o $(OBJ_DIR)/list_files.o  

$(OBJ_DIR)/searchString.o: $(SRC_DIR)/searchString.c $(INCLUDE_DIR)/common.h $(INCLUDE_DIR)/functions.h
	$(CC) $(CFLAGS) $(TFLAGS) -c $(SRC_DIR)/searchString.c -o $(OBJ_DIR)/searchString.o 

$(OBJ_DIR)/log.o: $(SRC_DIR)/log.c $(INCLUDE_DIR)/common.h $(INCLUDE_DIR)/functions.h
	$(CC) $(CFLAGS) $(TFLAGS) -c $(SRC_DIR)/log.c -o $(OBJ_DIR)/log.o

$(OBJ_DIR)/searchFile.o: $(SRC_DIR)/searchFile.c $(INCLUDE_DIR)/common.h $(INCLUDE_DIR)/functions.h
	$(CC) $(CFLAGS) $(TFLAGS) -c $(SRC_DIR)/searchFile.c -o $(OBJ_DIR)/searchFile.o  

$(OBJ_DIR)/server1.o: $(SRC_DIR)/server1.c $(INCLUDE_DIR)/common.h $(INCLUDE_DIR)/functions.h
	$(CC) $(CFLAGS) $(TFLAGS) -c $(SRC_DIR)/server1.c -o $(OBJ_DIR)/server1.o  

clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/*
valgrind-client1: $(EXECUTABLES)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose $(BIN_DIR)/client1 > $(REPORTS_DIR)/valgrind_client1.txt 2>&1

valgrind-server1: $(EXECUTABLES)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose $(BIN_DIR)/server1 > $(REPORTS_DIR)/valgrind_server1.txt 2>&1
