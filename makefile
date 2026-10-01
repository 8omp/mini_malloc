FILES = ./src/main.c

TARGET = mini_malloc

CC = gcc
CFLAGS = -g -Wall -I ./include/

SRCS = $(FILES) ./src/mini_malloc.c

all:
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)