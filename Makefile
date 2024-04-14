CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c11 -g -fsanitize=address
LDFLAGS = -lm -fsanitize=address

TAIL_TARGET = ./bin/tail
TAIL_SRC = ./src/tail.c ./src/cbuf.c

LIB_TARGET_STATIC = ./lib/libhtab.a
LIB_TARGET_SHARED = ./lib/libhtab.so
LIB_SRC = ./lib/htab_init.o ./lib/htab_size.o ./lib/htab_bucket_count.o ./lib/htab_find.o ./lib/htab_lookup_add.o ./lib/htab_erase.o ./lib/htab_for_each.o ./lib/htab_clear.o ./lib/htab_free.o ./lib/htab_statistics.o

WORDCOUNT_STATIC_TARGET = ./bin/wordcount
WORDCOUNT_DYNAMIC_TARGET = ./bin/wordcount-dynamic
WORDCOUNT_SRC = ./src/wordcount.c

all: tail wordcount wordcount-dynamic

tail:
	$(CC) $(CFLAGS) -o $(TAIL_TARGET) $(TAIL_SRC) $(LDFLAGS)

htab_init.o:
	$(CC) -c -fPIC $(CFLAGS) ./src/htab_init.c -o ./lib/htab_init.o

htab_size.o:
	$(CC) -c -fPIC $(CFLAGS) ./src/htab_size.c -o ./lib/htab_size.o

htab_bucket_count.o:
	$(CC) -c -fPIC $(CFLAGS) ./src/htab_bucket_count.c -o ./lib/htab_bucket_count.o

htab_find.o:
	$(CC) -c -fPIC $(CFLAGS) ./src/htab_find.c -o ./lib/htab_find.o

htab_lookup_add.o:
	$(CC) -c -fPIC $(CFLAGS) ./src/htab_lookup_add.c -o ./lib/htab_lookup_add.o

htab_erase.o:
	$(CC) -c -fPIC $(CFLAGS) ./src/htab_erase.c -o ./lib/htab_erase.o

htab_for_each.o:
	$(CC) -c -fPIC $(CFLAGS) ./src/htab_for_each.c -o ./lib/htab_for_each.o

htab_clear.o:
	$(CC) -c -fPIC $(CFLAGS) ./src/htab_clear.c -o ./lib/htab_clear.o

htab_free.o:
	$(CC) -c -fPIC $(CFLAGS) ./src/htab_free.c -o ./lib/htab_free.o

htab_statistics.o:
	$(CC) -c -fPIC $(CFLAGS) ./src/htab_statistics.c -o ./lib/htab_statistics.o

htab_hash_function.o:
	$(CC) -c -fPIC $(CFLAGS) ./src/htab_hash_function.c -o ./lib/htab_hash_function.o

wordcount: htab_init.o htab_size.o htab_bucket_count.o htab_find.o htab_lookup_add.o htab_erase.o htab_for_each.o htab_clear.o htab_free.o htab_statistics.o htab_hash_function.o
	ar rcs $(LIB_TARGET_STATIC) ./lib/htab*.o
	$(CC) $(CFLAGS) -o $(WORDCOUNT_STATIC_TARGET) $(WORDCOUNT_SRC) $(LIB_TARGET_STATIC) $(LDFLAGS)

wordcount-dynamic: htab_init.o htab_size.o htab_bucket_count.o htab_find.o htab_lookup_add.o htab_erase.o htab_for_each.o htab_clear.o htab_free.o htab_statistics.o
	$(CC) -shared -fPIC ./lib/htab*.o -o $(LIB_TARGET_SHARED)
	$(CC) $(CFLAGS) -o $(WORDCOUNT_DYNAMIC_TARGET) $(WORDCOUNT_SRC) $(LIB_TARGET_SHARED) $(LDFLAGS)

clean:
	rm ./bin/tail ./bin/wordcount ./bin/wordcount-dynamic ./lib/libhtab.a ./lib/libhtab.so ./lib/htab*.o
