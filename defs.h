//
// Created by heijo on 17/05/09.
//

#ifndef CHARCNT_SRT_DEFS_H
#define CHARCNT_SRT_DEFS_H

#endif //CHARCNT_SRT_DEFS_H
//
// Created by heijo
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define LIST_SIZE 123
#define START 48

typedef struct myChar{
    char c;
    int n;
}MYCHAR;

void quicksort(MYCHAR LIST[], int left, int right);
void count(int opt, char *filename);