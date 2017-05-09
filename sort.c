//
// Created by heijo on 17/05/09.
//



#include "defs.h"

int med3(int x, int y, int z)
/* x, y, z の中間値を返す */
{
    if (x < y)
        if (y < z) return y; else if (z < x) return x; else return z; else
    if (z < y) return y; else if (x < z) return x; else return z;
}

void quicksort(MYCHAR LIST[], int left, int right){
    if (left < right) {
        int i = left, j = right;
        int tmp, pivot = med3(LIST[i].n, LIST[i + (j - i) / 2].n, LIST[j].n); /* (i+j)/2ではオーバーフローしてしまう */
        char c;
        while (1) { /* LIST[] を pivot 以上と以下の集まりに分割する */
            while (LIST[i].n < pivot) i++; /* LIST[i].n >= pivot となる位置を検索 */
            while (pivot < LIST[j].n) j--; /* LIST[j].n <= pivot となる位置を検索 */
            if (i >= j) break;
            tmp = LIST[i].n; LIST[i].n = LIST[j].n; LIST[j].n = tmp; /* a[i],a[j] を交換 */
            c = LIST[i].c; LIST[i].c = LIST[j].c; LIST[j].c = c; /* a[i],a[j] を交換 */
            i++; j--;
        }
        quicksort(LIST, left, i - 1);  /* 分割した左を再帰的にソート */
        quicksort(LIST, j + 1, right); /* 分割した右を再帰的にソート */
    }
}
