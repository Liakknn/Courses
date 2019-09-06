#include "../include/libutils/Sort.h"

void sort_bubble(int* data, int n) {
    int tmp;
    for(int i = n - 1; i >= 0; --i) {
        bool swap = false;
        for(int j = 0; j < i; ++j) {
            if(data[j] < data[j + 1]) {
                tmp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tmp;
                swap = true;
            }
        }
        if(swap == false) {
            break;
        }
    }
}
/*
void sort_bubble(int* data, int n) {
    int tmp;
    for(int i = 0; i < n; ++i) {
        bool swap = false;
        for(int j = n - 1; j > i; --j) {
            if(data[j] < data[j - 1]) {
                tmp = data[j];
                data[j] = data[j - 1];
                data[j - 1] = tmp;
                swap = true;
            }
        }
        if(swap == false) {
            break;
        }
    }
}
 */