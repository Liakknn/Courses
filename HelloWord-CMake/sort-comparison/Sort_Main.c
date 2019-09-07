#include <libutils/Sort.h>
#include <stdio.h>
#include <time.h>


bool compareArrays(int *a, int *b, size_t count) {
    for (size_t i = 0; i < count; ++i)
        if (a[i] != b[i])
            return false;
    return true;
}

void testSort(size_t n, size_t m) {
    int *masBubbleSort = malloc(sizeof(int) * n);
    int *masSelectionSort = malloc(sizeof(int) * n);
    int *masShakerSort = malloc(sizeof(int) * n);
    int *masQuickSort = malloc(sizeof(int) * n);
    clock_t finish1;
    clock_t finish2;
    clock_t finish3;
    clock_t finish4;
    for (size_t i = 0; i < m; i++) {
        for (size_t k = 0; k < n; ++k) {
            int r = 0;
            r = rand() % 100;
            masBubbleSort[i] = r;
            masSelectionSort[i] = r;
            masShakerSort[i] = r;
            masQuickSort[i] = r;
        }
        clock_t start = clock();
        sort_bubble(masBubbleSort, n);
        finish1 += clock() - start;
        start = clock();
        sort_selection(masSelectionSort, n);
        finish2 += clock() - start;
        start = clock();
        sort_shaker(masShakerSort, n);
        finish3 += clock() - start;
        start = clock();
        sort_quick(masQuickSort, n);
        finish4 += clock() - start;
    }
    printf("Среднее время выполнения Sort_Bubble: %f\n", ((double) finish1 / CLOCKS_PER_SEC / m));
    printf("Среднее время выполнения Sort_Selection: %f\n", ((double) finish2 / CLOCKS_PER_SEC) / m);
    printf("Среднее время выполнения Sort_Shaker: %f\n", ((double) finish3 / CLOCKS_PER_SEC) / m);
    printf("Среднее время выполнения Sort_Quick: %f\n", ((double) finish4 / CLOCKS_PER_SEC) / m);

    if (!(
            compareArrays(masBubbleSort, masSelectionSort, n
            ) &&
            compareArrays(masSelectionSort, masShakerSort, n
            ) &&
            compareArrays(masShakerSort, masQuickSort, n
            ))) {
        printf("Массивы не сопадают\n");
    }

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