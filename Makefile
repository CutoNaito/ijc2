CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c11 -g -fsanitize=address
LDFLAGS = -lm -fsanitize=address

TAIL_TARGET = ./bin/tail
TAIL_SRC = ./src/tail.c ./src/cbuf.c

LIB_TARGET_STATIC = ./lib/libhtab.a
LIB_TARGET_SHARED = ./lib/libhtab.so
LIB_SRC = ./src/libhtab.c

WORDCOUNT_STATIC_TARGET = ./bin/wordcount
WORDCOUNT_DYNAMIC_TARGET = ./bin/wordcount-dynamic
WORDCOUNT_SRC = ./src/wordcount.c

all: tail wordcount wordcount-dynamic

tail:
	$(CC) $(CFLAGS) -o $(TAIL_TARGET) $(TAIL_SRC) $(LDFLAGS)

wordcount:
	$(CC) -c -fPIC $(CFLAGS) $(LIB_SRC) -o ./lib/libhtab.o
	ar rcs $(LIB_TARGET_STATIC) ./lib/libhtab.o
	$(CC) $(CFLAGS) -o $(WORDCOUNT_STATIC_TARGET) $(WORDCOUNT_SRC) $(LIB_TARGET_STATIC) $(LDFLAGS)

wordcount-dynamic:
	$(CC) -c -fPIC $(CFLAGS) $(LIB_SRC) -o ./lib/libhtab.o
	$(CC) -shared -fPIC ./lib/libhtab.o -o $(LIB_TARGET_SHARED)
	$(CC) $(CFLAGS) -o $(WORDCOUNT_DYNAMIC_TARGET) $(WORDCOUNT_SRC) $(LIB_TARGET_SHARED) $(LDFLAGS)

run: 
	./bin/tail

clean:
	rm ./bin/tail ./bin/wordcount ./bin/wordcount-dynamic ./lib/libhtab.a ./lib/libhtab.so ./lib/libhtab.o
