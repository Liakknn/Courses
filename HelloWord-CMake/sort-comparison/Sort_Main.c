#include <libutils/Sort.h>
#include <stdio.h>
#include <time.h>


bool compareArrays(int * a, int * b, size_t count) {
    for ( size_t i = 0; i < count; ++i )
        if ( a[i] != b[i] )
            return false;
    return true;
}

void testSort(size_t n, size_t m) {
    int *masBubbleSort = malloc(sizeof(int) * n);
    int *masSelectionSort = malloc(sizeof(int) * n);
    int *masShakerSort = malloc(sizeof(int) * n);
    int *masQuickSort = malloc(sizeof(int) * n);
    int r = 0;
    clock_t start;
    clock_t fihish1;
    clock_t finish2;
    clock_t finish3;
    clock_t finish4;
    for (size_t i = 0; i < n; i++) {
        r = rand() % 100;
        masBubbleSort[i] = r;
        masSelectionSort[i] = r;
        masShakerSort[i] = r;
        masQuickSort[i] = r;
        start = clock();
        for(size_t j = 0; j < m; ++j) {
            sort_bubble(masBubbleSort, n);
            fihish1 += clock();
        }
    }


    clock_t start1 = clock();
    for(size_t i = 0; i < m; ++i) {
        masBubbleSort[i] = rand() % 100;
        sort_bubble(masBubbleSort, n);
    }
    clock_t finish1 = clock();
    clock_t start2 = clock();
    for(size_t i = 0; i < m; ++i) {
        sort_selection(masSelectionSort, n);
    }
    clock_t finish2 = clock();
    clock_t start3 = clock();
    for(size_t i = 0; i < m; ++i) {
        sort_shaker(masShakerSort, n);
    }
    clock_t finish3 = clock();
    clock_t start4 = 0;
    for(size_t i = 0; i < m; ++i) {
        sort_quick(masQuickSort, n);
    }
    clock_t finish4 = clock();
    if(!(compareArrays(masBubbleSort,masSelectionSort,n)&&compareArrays(masSelectionSort,masShakerSort,n)&&compareArrays(masShakerSort,masQuickSort,n))){
        printf("Массивы не сопадают\n");
    }
    printf("Среднее время выполнения Sort_Bubble: %f\n", ((double)(finish1 - start1) / CLK_TCK));
    printf("Среднее время выполнения Sort_Selection: %f\n", ((double)(finish2 - start2) / CLK_TCK));
    printf("Среднее время выполнения Sort_Shaker: %f\n", ((double)(finish3 - start3) / CLK_TCK));
    printf("Среднее время выполнения Sort_Quick: %f\n", ((double)(finish4 - start4)/ CLK_TCK));
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
    //int p4[] = {2, 1, 9, 6, 5, 6, 8, 9, 0, 1, 2, 3};
    testSort(1000, 1000);
    //sort_selection(p4, 5);
    //sort_bubble(p4, 5);
    //sort_shaker(p4, 5);
    //sort_quick(p4, 5);
    //NaturalMergeSort(p4, 12);
    //printArray(p4, 12);

}