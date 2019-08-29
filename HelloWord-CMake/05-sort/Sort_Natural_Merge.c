#include "Sort.h"


void merge(const int *p1, int n1, const int *p2, int n2, int *dst, bool forward) {
    int i = 0;
    int j = 0;
    int dstStart = forward ? 0 : n1 + n2 - 1;
    int dstOrientation = forward ? +1 : -1;
    for (int k = 0; k < n1 + n2; ++k) {
        if (i < n1 && j >= 0) {
            //в обоих списках есть элементы
            if (p1[i] < p2[n2 - 1 - j]) {
                dst[dstStart + (i+j)*dstOrientation] = p1[i];
                ++i;
            } else {
                dst[dstStart + (i+j)*dstOrientation] = p2[n2 - 1 - j];
                j++;
            }
        } else if (i < n1) {
            //элементы только в первом списке
            dst[dstStart + (i+j)*dstOrientation] = p1[i];
            ++i;
        } else {
            //элементы только во втором списке
            dst[dstStart + (i+j)*dstOrientation] = p2[n2 - 1 - j];
            j++;
        }
    }
}


