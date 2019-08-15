#include <stdio.h>
#include "Matrix.h"

int main() {
	struct Matrix* m = CreateMatrix(FLAT, 2, 3);
	SetMatrixValue(m, 0, 0, 2.0f);
	printf("%.2f", GetMatrixValue(m, 0, 0));
}