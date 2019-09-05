#include "../include/libutils/Sort.h"

void sort_quick(int* data, int n) {
    if(n == 0 || n == 1) {
        return;
    }
    int mid = data[n / 2];
    int i = 0;
    int j = n - 1;
    while (i <= j) {
        while(i < n && data[i] < mid) ++i;
        while (j >= 0 && data[j] > mid) --j;
        if(i <= j) {
            int tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
            ++i;
            --j;
        }
    }
    if(j > 0) {
        sort_quick(data, j);
    }
    if(i < n) {
        sort_quick(data + i, n - i);
    }
}

