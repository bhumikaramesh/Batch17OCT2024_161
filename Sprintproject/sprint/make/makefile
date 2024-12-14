CC = gcc
CFLAGS = -Wall -g -I../include
 
SRC_DIR = ../src
OBJ_DIR = ../obj
BIN_DIR = ../bin
INCLUDE_DIR = ../include
 
SRC_FILES = $(SRC_DIR)/client.c $(SRC_DIR)/displayFileContent.c $(SRC_DIR)/list_files.c $(SRC_DIR)/searchString.c $(SRC_DIR)/server.c
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
EXECUTABLES = $(BIN_DIR)/client $(BIN_DIR)/server
 
all: $(EXECUTABLES)
 
$(BIN_DIR)/client: $(OBJ_DIR)/client.o 
	$(CC) $(CFLAGS) -o $(BIN_DIR)/client $(OBJ_DIR)/client.o 
 
$(BIN_DIR)/server: $(OBJ_DIR)/server.o $(OBJ_DIR)/displayFileContent.o  $(OBJ_DIR)/searchString.o $(OBJ_DIR)/list_files.o $(OBJ_DIR)/searchFile.o 
	$(CC) $(CFLAGS) -o $(BIN_DIR)/server $(OBJ_DIR)/server.o $(OBJ_DIR)/displayFileContent.o  $(OBJ_DIR)/searchString.o $(OBJ_DIR)/list_files.o $(OBJ_DIR)/searchFile.o 
 
$(OBJ_DIR)/client.o: $(SRC_DIR)/client.c $(INCLUDE_DIR)/common.h 
	$(CC) $(CFLAGS) -c $(SRC_DIR)/client.c -o $(OBJ_DIR)/client.o
 
$(OBJ_DIR)/displayFileContent.o: $(SRC_DIR)/displayFileContent.c $(INCLUDE_DIR)/common.h $(INCLUDE_DIR)/functions.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/displayFileContent.c -o $(OBJ_DIR)/displayFileContent.o
 
$(OBJ_DIR)/list_files.o: $(SRC_DIR)/list_files.c $(INCLUDE_DIR)/common.h $(INCLUDE_DIR)/functions.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/list_files.c -o $(OBJ_DIR)/list_files.o

$(OBJ_DIR)/searchString.o: $(SRC_DIR)/searchString.c $(INCLUDE_DIR)/common.h $(INCLUDE_DIR)/functions.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/searchString.c -o $(OBJ_DIR)/searchString.o
	
$(OBJ_DIR)/searchFile.o: $(SRC_DIR)/searchFile.c $(INCLUDE_DIR)/common.h $(INCLUDE_DIR)/functions.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/searchFile.c -o $(OBJ_DIR)/searchFile.o
 
$(OBJ_DIR)/server.o: $(SRC_DIR)/server.c $(INCLUDE_DIR)/common.h $(INCLUDE_DIR)/functions.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/server.c -o $(OBJ_DIR)/server.o
 
clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/*
 
