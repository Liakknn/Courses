#include "Matrix.h"
#include <stdlib.h>

struct Matrix *CreateMatrix(enum Type type, size_t rows, size_t cols) {
    struct Matrix *matrix = malloc(sizeof(struct Matrix));
    matrix->cols = cols;
    matrix->rows = rows;
    matrix->type = type;
    switch (type) {
        case FLAT:
            matrix->data = calloc(rows * cols, sizeof(float));
            return matrix;
        case ROW: {
            float **mas = (float **) malloc(rows * sizeof(float *));
            for (size_t i = 0; i < rows; i++) {
                mas[i] = (float *) calloc(cols, sizeof(float));
            }
            matrix->data = mas;
            return matrix;
        }
        case COLUMN: {
            float **mas = (float **) malloc(cols * sizeof(float *));
            for (size_t i = 0; i < cols; i++) {
                mas[i] = (float *) calloc(rows, sizeof(float));
            }
            matrix->data = mas;
            return matrix;
        }
        default:
            free(matrix);
            return NULL;
    }
}

void SetMatrixValue(struct Matrix *matrix, size_t row, size_t col, float value) {
    switch (matrix->type) {
        case FLAT: {
            float *data = (float *) matrix->data;
            data[row * matrix->cols + col] = value;
            break;
        }
        case ROW: {
            float **dataRows = (float **) matrix->data;
            float *dataRow = (float *) dataRows[row];
            dataRow[col] = value;
        }
        case COLUMN: {
            float **dataCols = (float **) matrix->data;
            float *dataCol = (float *) dataCols[col];
            dataCol[row] = value;
        }
    }
}

float GetMatrixValue(struct Matrix *matrix, size_t row, size_t col) {
    switch (matrix->type) {
        case FLAT: {
            float *data = (float *) matrix->data;
            return data[row * matrix->cols + col];
        }
        case ROW: {
            float **dataRows = (float **) matrix->data;
            float *dataRow = (float *) dataRows[row];
            return dataRow[col];
        }
        case COLUMN: {
            float **dataCols = (float **) matrix->data;
            float *dataCol = (float *) dataCols[col];
            return dataCol[row];
        }
    }
}

void PrintMatrix(struct Matrix *matrix, FILE *file) {
    if (file == NULL) {
        return;
    } else {
        for (size_t i = 0; i < matrix->rows; ++i) {
            for (size_t j = 0; j < matrix->cols; ++j) {
                fprintf(file, "%.2f ", GetMatrixValue(matrix, i, j));
            }
            printf("\n");
        }
    }
}

void DestroyMatrix(struct Matrix *matrix) {
    switch (matrix->type) {
        case FLAT: {
            free(matrix->data);
            matrix->rows = 0;
            matrix->cols = 0;
            free(matrix);
            break;
        }
        case ROW: {
            float **data = (float **) matrix->data;
            for (size_t i = 0; i < matrix->rows; ++i) {
                free(data[i]);
            }
            matrix->rows = 0;
            matrix->cols = 0;
            free(matrix);
            break;
        }
        case COLUMN: {
            float **data = (float **) matrix->data;
            for (size_t i = 0; i < matrix->cols; ++i) {
                free(data[i]);
            }
            matrix->rows = 0;
            matrix->cols = 0;
            free(matrix);
            break;
        }
    }
}
