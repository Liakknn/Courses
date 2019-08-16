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
            float **dataRow = (float **) matrix->data;
            float *dataCol = (float *) dataRow[row];
            dataCol[col] = value;
        }
        case COLUMN: {
            float **dataCol = (float **) matrix->data;
            float *dataRow = (float *) dataCol[col];
            dataRow[row] = value;
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
            float **dataRow = (float **) matrix->data;
            float *dataCol = (float *) dataRow[row];
            return dataCol[col];
        }
        case COLUMN:
        {

            float **dataCol = (float **) matrix->data;
            float *dataRow = (float *) dataCol[col];
            return dataRow[row];
        }
    }
}

void PrintMatrix(struct Matrix *matrix) {

}