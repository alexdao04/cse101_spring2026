CC = gcc
CFLAGS = -std=c17 -Wall -Wextra -g
TARGET = hw2

all: $(TARGET)

$(TARGET): hw2.o priority_queue.o
	$(CC) $(CFLAGS) -o $(TARGET) hw2.o priority_queue.o

hw2.o: hw2.c priority_queue.h
	$(CC) $(CFLAGS) -c hw2.c

priority_queue.o: priority_queue.c priority_queue.h
	$(CC) $(CFLAGS) -c priority_queue.c

clean:
	rm -f *.o $(TARGET)