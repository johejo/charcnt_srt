#include "defs.h"

//Get Intermediate value from x, y, z
int med3(int x, int y, int z) {
    if (x < y)
        if (y < z) return y; else if (z < x) return x; else return z; else
    if (z < y) return y; else if (x < z) return x; else return z;
}

//quick sort
void quicksort(MYCHAR LIST[], int left, int right){
    if (left < right) {
        int i = left, j = right;
        int tmp, pivot = med3(LIST[i].n, LIST[i + (j - i) / 2].n, LIST[j].n); //Choice pivot
        char c;
        while (1) {
            while (LIST[i].n < pivot) i++; //Search where LIST[i].n is greater than or equal to pivot
            while (pivot < LIST[j].n) j--; //Search where pivot is greater than or equal to LIST[j].n
            if (i >= j) break;

            //Swap LIST[i] and LIST[j]
            tmp = LIST[i].n; LIST[i].n = LIST[j].n; LIST[j].n = tmp;
            c = LIST[i].c; LIST[i].c = LIST[j].c; LIST[j].c = c;

            i++; j--;
        }
        //Sort recursively left and right
        quicksort(LIST, left, i - 1);
        quicksort(LIST, j + 1, right);
    }
}
