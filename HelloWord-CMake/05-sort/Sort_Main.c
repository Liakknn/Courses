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
    int p4[] = {2, 1, 9, 6, 5};
    sort_selection(p4, 5);
    for(int i = 0; i < 5; ++i) {
        printf("%d ", p4[i]);
    }
}