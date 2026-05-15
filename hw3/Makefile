#------------------------------------------------------------------------------
# Makefile for CSE 101 Hwk 3
#------------------------------------------------------------------------------

CC = gcc
CFLAGS = -std=c17 -Wall

TARGET = hw3

SOURCES = hw3.c Dictionary.c HashTable.c
OBJECTS = $(SOURCES:.c=.o)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

hw3.o: hw3.c Dictionary.h
	$(CC) $(CFLAGS) -c hw3.c

Dictionary.o: Dictionary.c Dictionary.h HashTable.h
	$(CC) $(CFLAGS) -c Dictionary.c

HashTable.o: HashTable.c HashTable.h
	$(CC) $(CFLAGS) -c HashTable.c

clean:
	rm -f $(TARGET) $(OBJECTS)
