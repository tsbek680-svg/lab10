
CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = hash

all: $(TARGET)

hash.o: hash.c DS.h
	$(CC) $(CFLAGS) -c hash.c -o hash.o

list.o: list.c DS.h
	$(CC) $(CFLAGS) -c list.c -o list.o

main.o: main.c DS.h
	$(CC) $(CFLAGS) -c main.c -o main.o

$(TARGET): hash.o main.o list.o
	$(CC) hash.o main.o list.o -o $(TARGET) -lm

clean:
	rm -f *.o $(TARGET)

.PHONY: all clean

