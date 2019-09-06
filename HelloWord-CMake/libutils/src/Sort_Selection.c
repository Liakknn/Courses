#include "../include/libutils/Sort.h"

int min(const int* data, int n) {
    int min = 0;
    for(int i = 1; i < n; ++i) {
        if(data[i] < data[min]) {
            min = i;
        }
    }
    return min;
}

void sort_selection(int* data, int n) {
    for(int i = 0; i < n - i; ++i) {
        int minIndex = i + min(data + i, n - i);
        int tmp = data[i];
        data[i] = data[minIndex];
        data[minIndex] = tmp;
    }
}
