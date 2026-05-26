CC = gcc
CFLAGS = -std=c17 -Wall -Wextra -g
TARGET = prog4
OBJS = prog4.o pathfinder.o Graph.o

.PHONY: all clean test

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

prog4.o: prog4.c Graph.h pathfinder.h
	$(CC) $(CFLAGS) -c prog4.c

pathfinder.o: pathfinder.c pathfinder.h Graph.h
	$(CC) $(CFLAGS) -c pathfinder.c

Graph.o: Graph.c Graph.h
	$(CC) $(CFLAGS) -c Graph.c

test: $(TARGET)
	./$(TARGET) graph.txt < commands.in

clean:
	rm -f $(TARGET) *.o
