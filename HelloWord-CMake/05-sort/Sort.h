#include <stdlib.h>
#include <stdbool.h>

void sort_selection(int* data, int n);
void merge(const int *p1, int n1, const int *p2, int n2, int *dst, bool forward);
void sort_bubble(int* data, int n);
void sort_shaker(int* data, int n);
void sort_quick(int* data, int n);