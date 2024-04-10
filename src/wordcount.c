#include <stdio.h>
#include "htab.h"

void print_pair(htab_pair_t *pair)
{
    printf("%s\t%d\n", pair->key, pair->value);
}

int main(void)
{
    htab_t *t = htab_init(10);

    char buffer[100];

    while (fgets(buffer, 100, stdin) != NULL) {
        buffer[strlen(buffer) - 1] = '\0';
        htab_pair_t *pair = htab_lookup_add(t, buffer);
        pair->value++;
    }

    htab_for_each(t, print_pair);

    htab_free(t);

    return 0;
}
