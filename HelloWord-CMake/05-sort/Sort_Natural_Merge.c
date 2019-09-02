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
                dst[dstStart + (i + j) * dstOrientation] = p1[i];
                ++i;
            } else {
                dst[dstStart + (i + j) * dstOrientation] = p2[n2 - 1 - j];
                j++;
            }
        } else if (i < n1) {
            //элементы только в первом списке
            dst[dstStart + (i + j) * dstOrientation] = p1[i];
            ++i;
        } else {
            //элементы только во втором списке
            dst[dstStart + (i + j) * dstOrientation] = p2[n2 - 1 - j];
            j++;
        }
    }
}

int sequence(int *data, int n, bool forward) {
    int count = 1;
    if (forward) {
        while (count < n && data[count - 1] < data[count]) {
            ++count;
        }
    } else {
        while (count < n && data[n - count - 1] > data[n - count]) {
            ++count;
        }
    }
    return count;
}

void swap(int **a, int **b) {
    int* temp = *a;
    *a = *b;
    *b = temp;
}

void NaturalMergeSort(int *data, int n) {
    if (n < 2) {
        return;
    }
    int *buffer = malloc(sizeof(data));
    int count = 0;
    while (true) {
        int left = sequence(data, n, true);
        int right = sequence(data, n, false);
        merge(data, left, data + n - right, right, buffer, true);
        if(left + right == n + 1) {
            break;
        }
        int left2 = sequence(data + left, n - left - right, true);
        int right2 = sequence(data + left, n - left - right, false);
        merge(data + left, left2, data + n - right - right2, right2, buffer, false);
        ++count;
        if(count % 2 != 0) {
            swap(&data, &buffer);
        }
        for(int i = left + left2; i < n - right - right2; ++i) {
            buffer[i] = data[i];
        }
        for(int i = 0; i < n; ++i)  {
            data[i] = buffer[i];
        }
        free(buffer);
    }
}

