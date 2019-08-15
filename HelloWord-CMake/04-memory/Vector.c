
#include "Vector.h"
#include <stdio.h>

void vector_init(struct Vector *vector, size_t n) {
    vector->data = (float *) malloc(n * sizeof(float));
    if (vector->data == NULL) {
        vector->capacity = 0;
        vector->size = 0;
        return;
    }
    vector->capacity = n;
    vector->size = n;
    for (size_t i = 0; i < n; ++i) {
        vector->data[i] = (float) n;
    }
}

void vector_print(const struct Vector *vector) {
    for (size_t i = 0; i < vector->size; ++i) {
        printf("%.2f ", vector->data[i]);
    }
    printf("\n");
}

int firstIndexOf(const struct Vector *vector, float n) {
    for (size_t i = 0; i < vector->size; ++i) {
        if (vector->data[i] == n) {
            return i;
        }
    }
    return -1;
}

int lastIndexOf(const struct Vector *vector, float n) {
    int index = -1;
    for (size_t i = 0; i < vector->size; ++i) {
        if (vector->data[i] == n) {
            index = i;
        }
    }
    return index;
}

void insert(struct Vector *vector, size_t index, float n) {
    if (index > vector->size) {
        return;
    }
    if(vector->size < vector->capacity) {
        vector->size++;
        for(size_t i = index; i < vector->size; ++i) {
            vector->data[i + 1] = vector->data[i];
        }
        vector->data[index] = n;
    }
    float mas[vector->size + 1];
    for (size_t i = 0; i < index; ++i) {
        mas[i] = vector->data[i];
    }
    mas[index] = n;
    for (size_t i = index; i < vector->size; ++i) {
        mas[i + 1] = vector->data[i];
    }
    if (vector->capacity == vector->size) {
        free(vector->data);
        vector->data = malloc(sizeof(float) * vector->capacity * 2);
    }
    for (size_t i = 0; i <= vector->size; ++i) {
        vector->data[i] = mas[i];
    }
    vector->size += 1;
    vector->capacity *= 2;
}



