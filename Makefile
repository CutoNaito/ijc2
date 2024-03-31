CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c11 -g
LDFLAGS = -lm

tail:
	$(CC) $(CFLAGS) -o tail tail.c $(LDFLAGS)

all: tail

run: 
	./bin/tail

clean:
	rm ./bin/tail
