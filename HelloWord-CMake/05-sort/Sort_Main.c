#include "Sort.h"
#include <stdio.h>

int main() {
    int p1[] = {1, 3, 4};
    int p2[] = {6, 5, 2};
    int p3[6];
    merge(p1, 3, p2, 3, p3, false);
    for (int i = 0; i <6 ; ++i) {
        printf("%d ",p3[i]);
    }
    printf("\n");
    int p4[] = {2, 1, 9, 6, 5, 6, 8, 9, 0, 1, 2, 3};
    //sort_selection(p4, 5);
    //sort_bubble(p4, 5);
    //sort_shaker(p4, 5);
    //sort_quick(p4, 5);
    NaturalMergeSort(p4, 12);
    for(int i = 0; i < 12; ++i) {
        printf("%d ", p4[i]);
    }
}