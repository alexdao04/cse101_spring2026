CC = gcc
CFLAGS = -std=c17 -Wall -Wextra -g
TARGET = prog2

all: $(TARGET)

$(TARGET): prog2.o runway_scheduler.o priority_queue.o
	$(CC) $(CFLAGS) -o $(TARGET) prog2.o runway_scheduler.o priority_queue.o

prog2.o: prog2.c runway_scheduler.h priority_queue.h
	$(CC) $(CFLAGS) -c prog2.c

runway_scheduler.o: runway_scheduler.c runway_scheduler.h priority_queue.h
	$(CC) $(CFLAGS) -c runway_scheduler.c

priority_queue.o: priority_queue.c priority_queue.h
	$(CC) $(CFLAGS) -c priority_queue.c

clean:
	rm -f *.o $(TARGET)