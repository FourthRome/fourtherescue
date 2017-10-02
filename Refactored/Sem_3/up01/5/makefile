CC = gcc
CFILES = test.c
TARGET = test
CFLAGS = -O2 -Wall -Werror -Wno-pointer-sign -std=gnu11 -fsanitize=undefined

all:
	$(CC) $(CFLAGS) $(CFILES) -o $(TARGET)

clear:
	rm -rf *.o $(TARGET)
