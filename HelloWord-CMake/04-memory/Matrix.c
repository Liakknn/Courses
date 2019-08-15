#include "Matrix.h"
#include <stdlib.h>

struct Matrix* CreateMatrix(enum Type type, size_t rows, size_t cols) {
	struct  Matrix* matrix = malloc(sizeof(struct Matrix));
	matrix->cols = cols;
	matrix->rows = rows;
	matrix->type = type;
	switch (type)	{
	case FLAT:
		matrix->data = calloc(rows * cols, sizeof(float));
		break;
	case ROW:
		/*matrix->data = 
		float* mas = calloc(cols)*/
		break;
	case COLUMN:

		break;
	default:
		free(matrix);
		return NULL;
	}
}

void SetMatrixValue(struct Matrix* matrix, size_t row, size_t col, float value) {
	switch (matrix->type) {
	case FLAT: {
		float* data = (float*)matrix->data;
		data[row * matrix->cols + col] = value;
		break;
	}
	case ROW:
		// TODO
		break;
	case COLUMN:
		//TODO
		break;
	}
}

float GetMatrixValue(struct Matrix* matrix, size_t row, size_t col) {
	switch (matrix->type) {
	case FLAT: {
		float* data = (float*)matrix->data;
		return data[row * matrix->cols + col];
	}
	case ROW:
		// TODO
		break;
	case COLUMN:
		//TODO
		break;
	}
}

void PrintMatrix(struct Matrix* matrix) {

}