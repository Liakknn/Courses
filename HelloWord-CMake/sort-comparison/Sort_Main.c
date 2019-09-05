#include "../libutils/include/libutils/Sort.h"
#include <stdio.h>


bool compareArrays(int * a, int * b, size_t count) {
    for ( size_t i = 0; i < count; ++i )
        if ( a[i] != b[i] )
            return false;
    return true;
}

void testSort(size_t n) {
    int *masBubbleSort = malloc(sizeof(int) * n);
    int *masSelectionSort = malloc(sizeof(int) * n);
    int *masShakerSort = malloc(sizeof(int) * n);
    int *masQuickSort = malloc(sizeof(int) * n);
    int r = 0;
    for (size_t i = 0; i < n; i++) {
        r = rand() % 100;
        masBubbleSort[i] = r;
        masSelectionSort[i] = r;
        masShakerSort[i] = r;
        masQuickSort[i] = r;
    }
    sort_bubble(masBubbleSort, n);
    sort_selection(masSelectionSort, n);
    sort_shaker(masShakerSort, n);
    sort_quick(masQuickSort, n);

    if(!(compareArrays(masBubbleSort,masSelectionSort,n)&&compareArrays(masSelectionSort,masShakerSort,n)&&compareArrays(masShakerSort,masQuickSort,n))){
        printf("Массивы не сопадают\n");
    }
    printArray(masBubbleSort, n);
    printArray(masSelectionSort, n);
    printArray(masShakerSort, n);
    printArray(masQuickSort, n);
    free(masBubbleSort);
    free(masSelectionSort);
    free(masShakerSort);
    free(masQuickSort);
}

int main() {
    int p1[] = {1, 3, 4};
    int p2[] = {6, 5, 2};
    int p3[6];
    merge(p1, 3, p2, 3, p3, false);

    printf("\n");
    int p4[] = {2, 1, 9, 6, 5, 6, 8, 9, 0, 1, 2, 3};
    testSort(20);
    //sort_selection(p4, 5);
    //sort_bubble(p4, 5);
    //sort_shaker(p4, 5);
    //sort_quick(p4, 5);
    //NaturalMergeSort(p4, 12);
    //printArray(p4, 12);

}