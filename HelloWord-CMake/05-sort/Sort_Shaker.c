#include "Sort.h"

void sort_shaker(int* data, int n) {
    for(int i = 0; i < n / 2; ++i) {
        bool swap = false;
        for(int j = i; j < n - 1 - i; ++j) {
            if(data[j] > data[j + 1]) {
                int tmp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tmp;
                swap = true;
            }
        }
        for(int j = n - 2 - i; j > i; --j) {
            if(data[j] < data[j - 1]) {
                int tmp = data[j];
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