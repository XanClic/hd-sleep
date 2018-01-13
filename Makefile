CC = gcc
RM = rm -f

.PHONY: all clean

all: hd-sleep

hd-sleep: hd-sleep.c
	$(CC) -Wall -Wextra -pedantic -std=c11 -O3 $< -o $@

clean:
	$(RM) hd-sleep
