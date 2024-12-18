CC=gcc
cflags=-c
oflags=-o

INC=./inc
OBJ=./obj
SRC=./src
BIN=./bin
LIB=./lib

iflags=-I$(INC)/

#targetapp: target1 target2
#	gcc -o ./bin/target target1 target2

#target1: dependencies1
#	gcc -c sourcecodes

#target2: dependencies2
#	gcc -c sourcecodes

$(BIN)/app: $(OBJ)/main.o $(OBJ)/calc.o
	$(CC) $(oflags) $(BIN)/app $(OBJ)/main.o $(OBJ)/calc.o

$(OBJ)/main.o: $(SRC)/main.c
	$(CC) $(cflags) $(iflags) $(SRC)/main.c $(oflags) $(OBJ)/main.o

$(OBJ)/calc.o: $(SRC)/calc.c
	$(CC) $(cflags) $(iflags) $(SRC)/calc.c $(oflags) $(OBJ)/calc.o


clean:
	@echo "cleaining now"
	rm -rf ./bin/*
	rm -rf ./obj/*
	@echo "cleaning Done"
