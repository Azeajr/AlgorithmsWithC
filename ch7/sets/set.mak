CC=gcc
CFLAGS=-I
DEPS = set.h list.h

all: list.c set.c setTest.c
	gcc -o setTest.out list.o set.o setTest.o

setTest

list.o: list.c list.h
	cc -c list.c

set.o: set.c set.h
setTest.o