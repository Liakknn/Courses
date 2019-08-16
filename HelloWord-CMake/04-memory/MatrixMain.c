#include <stdio.h>
#include "Matrix.h"

int main() {
	struct Matrix* m = CreateMatrix(FLAT, 2, 3);
	SetMatrixValue(m, 0, 0, 2.0f);
	printf("%.2f\n", GetMatrixValue(m, 0, 0));
	struct Matrix* mR = CreateMatrix(ROW, 2, 3);
	SetMatrixValue(mR, 0, 1, 2.0f);
	printf("%.2f\n", GetMatrixValue(mR, 0, 1));
    PrintMatrix(mR, stdout);
}