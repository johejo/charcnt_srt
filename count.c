//
// Created by heijo on 17/05/09.
//

#include "defs.h"

void count(int opt, char *filename){
    //open file
    FILE *fp;
    if ((fp = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "Cannot open %s.", filename);
        exit(EXIT_FAILURE);
    }

    //set characters
    MYCHAR LIST[LIST_SIZE - START];
    unsigned int i;
    MYCHAR *p;
    for(i = START, p = LIST; i < LIST_SIZE; i++, p++) {
        p -> c = (char)i;
        p -> n = 0;
    }

    //seek end of file
    fseek(fp, 0, SEEK_END);
    size_t size = (size_t)ftell(fp);

    //secure memory
    char *rdata;
    rdata = (char *)calloc(size, sizeof(char));
    fseek(fp, 0, SEEK_SET);

    //read file
    size_t n = fread(rdata, sizeof(char), size, fp);
    if (n == 0) {
        fprintf(stderr, "Cannot read %s.", filename);
        exit(EXIT_FAILURE);
    }

    fclose(fp);

    //count num of each characters
    char *b = rdata;
    for(i = 0, p = LIST; i < size; i++, b++) {
       ((p + (*b) - START) -> n)++;
    }

    free(rdata);

    quicksort(LIST, 0, LIST_SIZE - START);

//    print result
    for (i = START, p = LIST; i < LIST_SIZE; i++, p++) {
        printf("%c:%d\n", p -> c, p -> n);
    }
}
