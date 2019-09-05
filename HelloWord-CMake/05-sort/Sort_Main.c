#include "Sort.h"
#include <stdio.h>


void test(int n) {
    int* buffer1 = malloc(sizeof(int) * n);
    int* buffer2 = malloc(sizeof(int) * n);
    int* buffer3 = malloc(sizeof(int) * n);
    int* buffer4 = malloc(sizeof(int) * n);
    for(int i = 0; i < n; ++i) {
        buffer1[i] = rand() % 100;
        printf("%d", buffer1[i]);
    }
    printf("\n");
    for(int i = 0; i < n; ++i) {
        buffer2[i] = rand() % 100;
        printf("%d", buffer2[i]);
    }
    printf("\n");
    
    for(int i = 0; i < n; ++i) {
        buffer3[i] = rand() % 100;
        printf("%d", buffer3[i]);
    }
    printf("\n");
    for(int i = 0; i < n; ++i) {
        buffer4[i] = rand() % 100;
        printf("%d", buffer4[i]);
    }
    printf("\n");

    free(buffer1);
    free(buffer2);
    free(buffer3);
    free(buffer4);
}

int main() {
    int p1[] = {1, 3, 4};
    int p2[] = {6, 5, 2};
    int p3[6];
    merge(p1, 3, p2, 3, p3, false);

    printf("\n");
    int p4[] = {2, 1, 9, 6, 5, 6, 8, 9, 0, 1, 2, 3};
    //sort_selection(p4, 5);
    //sort_bubble(p4, 5);
    //sort_shaker(p4, 5);
    //sort_quick(p4, 5);
    //NaturalMergeSort(p4, 12);
    //printArray(p4, 12);

}