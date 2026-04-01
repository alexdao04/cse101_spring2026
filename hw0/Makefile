CC = gcc
CFLAGS = -Wall -Wextra -std=c11

hw0: hw0.o stack.o
	$(CC) $(CFLAGS) -o hw0 hw0.o stack.o

hw0.o: hw0.c stack.h
	$(CC) $(CFLAGS) -c hw0.c

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c

clean:
	rm -f hw0 *.o output