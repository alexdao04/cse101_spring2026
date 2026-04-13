CC = gcc
CFLAGS = -Wall -Wextra -std=c11

all: TraceEdges

TraceEdges: TraceEdges.o List.o
	$(CC) $(CFLAGS) -o TraceEdges TraceEdges.o List.o

TraceEdges.o: TraceEdges.c List.h
	$(CC) $(CFLAGS) -c TraceEdges.c

List.o: List.c List.h
	$(CC) $(CFLAGS) -c List.c

clean:
	rm -f TraceEdges *.o