#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define END '~'
#define BEGIN '!'

typedef struct myChar{
    char c;
    int n;
}MYCHAR;

void quicksort(MYCHAR LIST[], int left, int right);
void count(int debug, int opt, char *filename);