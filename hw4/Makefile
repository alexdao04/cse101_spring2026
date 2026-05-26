CC = gcc
CFLAGS = -std=c17 -Wall -Wextra -g
TARGET = hw4
OBJS = hw4.o Graph.o

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

hw4.o: hw4.c Graph.h
	$(CC) $(CFLAGS) -c hw4.c

Graph.o: Graph.c Graph.h
	$(CC) $(CFLAGS) -c Graph.c

clean:
	rm -f $(TARGET) *.o
