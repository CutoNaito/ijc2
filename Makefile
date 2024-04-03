CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c11 -g
LDFLAGS = -lm

TAIL_TARGET = ./bin/tail
TAIL_SRC = ./src/tail.c ./src/cbuf.c

LIB_TARGET_STATIC = ./lib/libhtab.a
LIB_TARGET_SHARED = ./lib/libhtab.so
LIB_SRC = ./src/libhtab.c

WORDCOUNT_TARGET = ./bin/wordcount
WORDCOUNT_SRC = ./src/wordcount.c

tail:
	$(CC) $(CFLAGS) -o $(TAIL_TARGET) $(TAIL_SRC) $(LDFLAGS)

wordcount:
	$(CC) -c $(CFLAGS) $(LIB_SRC) -o ./lib/libhtab.o
	ar rcs $(LIB_TARGET_STATIC) ./lib/libhtab.o
	$(CC) -shared -o $(LIB_TARGET_SHARED) ./lib/libhtab.o
	$(CC) $(CFLAGS) -o $(WORDCOUNT_TARGET) $(WORDCOUNT_SRC) $(LIB_TARGET_STATIC) $(LDFLAGS)

all: tail

run: 
	./bin/tail

clean:
	rm ./bin/tail
