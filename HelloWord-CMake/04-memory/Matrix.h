#include <stdlib.h>
#include <stdio.h>

enum Type {
	FLAT,
	ROW,
	COLUMN,
	VIRTUAL
};

struct Matrix {
	void* data;
	enum Type type;
	size_t rows;
	size_t cols;
};

struct Matrix* CreateMatrix(enum Type type, size_t rows, size_t cols);

void SetMatrixValue(struct Matrix* matrix, size_t row, size_t col, float value);

float GetMatrixValue(struct Matrix* matrix, size_t row, size_t col);

void PrintMatrix(struct Matrix* matrix, FILE* file);

void DestroyMatrix(struct Matrix* matrix);

void SwapRows(struct Matrix* matrix1, struct Matrix* matrix2, size_t indexRow1, size_t indexRow2);
