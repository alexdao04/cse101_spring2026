#------------------------------------------------------------------------------
# Makefile for CSE 101 Prog 3
#------------------------------------------------------------------------------

CC = gcc
CFLAGS = -std=c17 -Wall

TARGET = prog3

SOURCES = prog3.c search_engine.c Dictionary.c HashTable.c
OBJECTS = $(SOURCES:.c=.o)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

prog3.o: prog3.c search_engine.h Dictionary.h
	$(CC) $(CFLAGS) -c prog3.c

search_engine.o: search_engine.c search_engine.h Dictionary.h
	$(CC) $(CFLAGS) -c search_engine.c

Dictionary.o: Dictionary.c Dictionary.h HashTable.h
	$(CC) $(CFLAGS) -c Dictionary.c

HashTable.o: HashTable.c HashTable.h
	$(CC) $(CFLAGS) -c HashTable.c

clean:
	rm -f $(TARGET) $(OBJECTS)
