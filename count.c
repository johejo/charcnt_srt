#include "defs.h"

void count(int debug, int opt, char *filename){
    //Open file
    FILE *fp;
    if ((fp = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "\nCannot open %s.\n", filename);
        exit(1);
    }

    //Set characters
    MYCHAR LIST[END - BEGIN];
    unsigned int i;
    MYCHAR *p;
    for(i = BEGIN, p = LIST; i < END; i++, p++) {
        p -> c = (char)i;
        p -> n = 0;
    }

    //Seek end of file
    fseek(fp, 0, SEEK_END);
    size_t size = (size_t)ftell(fp);

    //Secure memory
    char *rdata;
    rdata = (char *)calloc(size, sizeof(char));
    fseek(fp, 0, SEEK_SET);

    //Read file
    size_t n = fread(rdata, sizeof(char), size, fp);
    if (n == 0) {
        fprintf(stderr, "Cannot read %s.", filename);
        exit(EXIT_FAILURE);
    }

    fclose(fp);

    //Count num of each characters
    char *b = rdata;
    int t;
    for(i = 0; i < size; i++, b++) {
        t = (int)(*b);
        t = t - BEGIN;
        LIST[t].n++;
    }

    free(rdata);

    //Print result for each option
    switch (opt){
        case 'a':
            quicksort(LIST, 0, END - BEGIN);
            for (i = BEGIN, p = LIST; i < END; i++, p++) {
                if (!debug) {
                    if ((p -> c >= '!' && p -> c <= '/')) {
                        continue;
                    } else if ((p -> c >= ':' && p -> c <= '@')) {
                        continue;
                    } else if ((p -> c >= '[' && p -> c <= '`')) {
                        continue;
                    } else if ((p -> c >= '{' && p -> c <= '~')) {
                        continue;
                    }
                }
                printf("%c:%d\n", p -> c, p -> n);
            }
            printf("\n");
            break;
        case 'd':
            quicksort(LIST, 0, END -BEGIN);
            for (i = BEGIN, p = LIST + END - BEGIN - 1; i < END; i++, p--) {
                if (!debug) {
                    if ((p -> c >= '!' && p -> c <= '/')) {
                        continue;
                    } else if ((p -> c >= ':' && p -> c <= '@')) {
                        continue;
                    } else if ((p -> c >= '[' && p -> c <= '`')) {
                        continue;
                    } else if ((p -> c >= '{' && p -> c <= '~')) {
                        continue;
                    }
                }
                printf("%c:%d\n", p -> c, p -> n);
            }
            printf("\n");
            break;

        case 'm':
            for (i = BEGIN, p = LIST; i < END; i++, p++) {
                if (!debug) {
                    if ((p -> c >= '!' && p -> c <= '/')) {
                        continue;
                    } else if ((p -> c >= ':' && p -> c <= '@')) {
                        continue;
                    } else if ((p -> c >= '[' && p -> c <= '`')) {
                        continue;
                    } else if ((p -> c >= '{' && p -> c <= '~')) {
                        continue;
                    }
                }
                printf("%c:%d\n", p -> c, p -> n);
            }
            printf("\n");
            break;
        default:
            break;
    }
}
