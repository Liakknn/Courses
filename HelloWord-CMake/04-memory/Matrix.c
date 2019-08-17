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
            break;
        }
        case COLUMN: {
            float **dataCols = (float **) matrix->data;
            float *dataCol = (float *) dataCols[col];
            dataCol[row] = value;
            break;
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
            free(data);
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
            free(data);
            break;
        }
    }
}

void SwapRows(struct Matrix *matrix1, struct Matrix *matrix2, size_t indexRow1, size_t indexRow2) {
    if(matrix1->rows != matrix2->rows || matrix1->cols != matrix2->cols) { return; }
    if (matrix1->rows < indexRow1 || matrix2->rows < indexRow2) {
        return;
    } else if (matrix1->type == ROW && matrix2->type == ROW){
        float** data1 = (float**) matrix1->data;
        float** data2 = (float**) matrix2->data;
        float* tmp = (float*) data2[indexRow2];
        data2[indexRow2] = data1[indexRow1];
        data1[indexRow1] = tmp;
    }
    else  {
        for(size_t i = 0; i < matrix1->cols; ++i) {
            float tmp = GetMatrixValue(matrix2, indexRow2, i);
            SetMatrixValue(matrix2, indexRow2, i, GetMatrixValue(matrix1, indexRow1, i));
            SetMatrixValue(matrix1, indexRow1, i, tmp);
        }
    }
}

