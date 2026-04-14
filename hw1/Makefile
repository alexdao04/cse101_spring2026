CC = gcc
CFLAGS = -std=c17 -Wall -Wextra -g

EXEC = hw1
OBJS = hw1.o List.o

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

hw1.o: hw1.c List.h
	$(CC) $(CFLAGS) -c hw1.c

List.o: List.c List.h
	$(CC) $(CFLAGS) -c List.c

clean:
	rm -f $(EXEC) *.o