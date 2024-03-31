#include "cbuf.h"

int main(int argc, char **argv)
{
    FILE *fp;
    unsigned long lines_to_read;

    switch (argc) {
    case 1:
        fp = stdin;
        lines_to_read = 10;
        break;

    case 2:
        if (strcmp(argv[1], "-n") == 0) {
            fprintf(stderr, "Error: option requires an argument -- 'n'\n");
            return 1;
        } else {
            fp = fopen(argv[1], "r");
            if (fp == NULL) {
                fprintf(stderr, "Error: cannot open file '%s'\n", argv[1]);
                return 1;
            }

            lines_to_read = 10;
        }

        break;

    case 3:
        if (strcmp(argv[1], "-n") != 0) {
            fprintf(stderr, "Error: invalid option -- '%s'\n", argv[1]);
            return 1;
        }

        fp = stdin;
        lines_to_read = strtoul(argv[2], NULL, 10);

        break;

    case 4:
        if (strcmp(argv[1], "-n") == 0) {
            lines_to_read = strtoul(argv[2], NULL, 10);
            fp = fopen(argv[3], "r");
            if (fp == NULL) {
                fprintf(stderr, "Error: cannot open file '%s'\n", argv[3]);
                return 1;
            }
        } else if (strcmp(argv[2], "-n") == 0) {
            lines_to_read = strtoul(argv[3], NULL, 10);
            fp = fopen(argv[1], "r");
            if (fp == NULL) {
                fprintf(stderr, "Error: cannot open file '%s'\n", argv[1]);
                return 1;
            }
        } else {
            fprintf(stderr, "Error: invalid option -- '%s'\n", argv[1]);
            return 1;
        }

        break;
    }

    return 0;
}