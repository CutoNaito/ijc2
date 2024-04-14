// io.h
// Řešení IJC-DU2, příklad 2), 14.4.2024
// Autor: Matěj Šturma, FIT
// Přeloženo: gcc 13.2.1

#ifndef __IO_H
#define __IO_H

#include <stdio.h>

/*
 * Function read_word reads a word from a file until it reaches a whitespace character or a null terminator and stores it in a buffer.
 * 
 * Return value is the length of the word.
 * */
int read_word(char *s, int max, FILE *f);

#endif
