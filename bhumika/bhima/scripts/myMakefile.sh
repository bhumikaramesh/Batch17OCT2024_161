CC=gcc
cflags=-c
oflags=-o
OBJ=./obj
SRC=./src
INC=./inc
BIN=./bin
LIB=./lib

echo $CC
echo $cflags
echo $oflags

echo "Cleaning of the files"
rm -rf $OBJ/*
rm -rf $BIN/*

echo "Building the files"
$CC $cflags -I$INC/ $SRC/main.c $oflags $OBJ/main.o
$CC $cflags -I$INC/ $SRC/calc.c $oflags $OBJ/calc.o
$CC $oflags $BIN/app $OBJ/calc.o $OBJ/main.o

