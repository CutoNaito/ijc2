CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c11 -g
LDFLAGS = -lm

TAIL_TARGET = ./bin/tail
TAIL_SRC = ./src/tail.c ./src/cbuf.c

tail:
	$(CC) $(CFLAGS) -o $(TAIL_TARGET) $(TAIL_SRC) $(LDFLAGS)

all: tail

run: 
	./bin/tail

clean:
	rm ./bin/tail
