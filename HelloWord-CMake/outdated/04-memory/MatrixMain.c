#include <stdio.h>
#include "Matrix.h"

int main() {
	struct Matrix* m = CreateMatrix(FLAT, 2, 3);
	SetMatrixValue(m, 0, 0, 2.0f);
	printf("%.2f\n", GetMatrixValue(m, 0, 0));
	struct Matrix* mR = CreateMatrix(ROW, 2, 3);
	SetMatrixValue(mR, 0, 1, 2.0f);
	printf("%.2f\n", GetMatrixValue(mR, 0, 1));
	FILE* f = fopen("test.txt", "w");
    PrintMatrix(mR, f);
    printf("\n");
    //DestroyMatrix(m);
    PrintMatrix(mR, stdout);
    printf("\n");
    PrintMatrix(m, stdout);
    SwapRows(mR, m, 1, 0);
    printf("\n");
    PrintMatrix(mR, stdout);
    printf("\n");
    PrintMatrix(m, stdout);

    struct Matrix* m1 = CreateMatrix(FLAT, 2, 3);
    struct Matrix* mR1 = CreateMatrix(ROW, 2, 4);
    SetMatrixValue(m1, 0, 1, 2.0f);
    SwapRows(mR1, m1, 1, 0);
    printf("\n");
    PrintMatrix(m1, stdout);
    struct Matrix* mC = CreateMatrix(COLUMN, 2, 3);
    struct Matrix* mC1 = CreateMatrix(COLUMN, 2, 3);
    SetMatrixValue(mC, 0, 1, 2.0f);
    SetMatrixValue(mC, 0, 0, 2.0f);
    PrintMatrix(mC, stdout);
    SwapRows(mC1, mC, 1, 0);
    printf("\n");
    PrintMatrix(mC, stdout);
    printf("\n");
    PrintMatrix(mC1, stdout);
    free(m);
    free(mR);
    free(m1);
    free(mC);
    free(mC1);
    free(mR1);
}