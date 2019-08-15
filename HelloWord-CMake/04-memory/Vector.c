
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

int firstIndexOf(const struct Vector *vector, predicate p) {
    for (int i = 0; i < vector->size; ++i) {
        if (p(vector->data[i])) {
            return i;
        }
    }
    return -1;
}

int lastIndexOf(const struct Vector *vector, predicate p) {
    int index = -1;
    for (int i = 0; i < vector->size; ++i) {
        if (p(vector->data[i])) {
            index = i;
        }
    }
    return index;
}

void insert(struct Vector* vector, size_t index, float n) {
	if (index > vector->size) {
		return;
	}
	if (vector->size < vector->capacity) {
		vector->size++;
		for (size_t i = vector->size; i > index; i--) {
			vector->data[i] = vector->data[i - 1];
		}
		vector->data[index] = n;
	} else {
		float* tmp = malloc(sizeof(float) * vector->capacity * 2);
		for (size_t i = 0; i < index; ++i) {
			tmp[i] = vector->data[i];
		}
		tmp[index] = n;
		for (size_t i = index; i < vector->size; ++i) {
			tmp[i + 1] = vector->data[i];
		}
		free(vector->data);
		vector->data = tmp;
		vector->size += 1;
		vector->capacity *= 2;
	}
}

void remove_element(struct Vector* vector, size_t index) {
	if (index > vector->size) { return; }
	for (size_t i = index; i < vector->size; ++i) {
		vector->data[i] = vector->data[i + 1];
	}
	vector->size--;
}



