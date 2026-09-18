FILES = 

TARGET = my_malloc

CC = gcc
CFLAGS = -Wall -I ./include/

SRCS = $(FILES)

all:
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)