FILES = ./src/main.c

TARGET = my_malloc

CC = gcc
CFLAGS = -Wall -I ./include/

SRCS = $(FILES) ./src/mini_malloc.c

all:
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)