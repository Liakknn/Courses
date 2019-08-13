
#include "Vector.h"
#include <stdio.h>

void vector_init(struct Vector* vector, size_t n) {
	vector->data = (float*)malloc(n * sizeof(float));
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

void vector_print(const struct Vector* vector) {
	for (size_t i = 0; i < vector->size; ++i) {
		printf("%.2f ", vector->data[i]);
	}
	printf("\n");
}

int firstIndexOf(const struct Vector* vector, float n) {
    for (size_t i = 0; i < vector->size; ++i) {
        if(vector->data[i] == n) {
            return i;
        }
    }
    return -1;
}

int lastIndexOf(const struct Vector* vector, float n) {
    int index = -1;
    for(size_t i = 0; i < vector->size; ++i) {
        if(vector->data[i] == n) {
            index = i;
        }
    }
    return index;
}


