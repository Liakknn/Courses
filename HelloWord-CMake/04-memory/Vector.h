#include<stdlib.h>
#include <stdbool.h>

typedef bool (*predicate) (float);

/** Структура для работы с динамическим массивом float
*/
struct Vector {
	float* data;   /*< указатель на данные */
	size_t capacity;  /*< количество элементов под которые выделена память */
	size_t size;      /*< реальное количество элементов */
};

/**Инициилизирует указатель vector
@param vector указатель на структуру Vector, не должен быть равен NULL
@param n количество элементов 
*/

void vector_init(struct Vector* vector, size_t n);

void vector_print(const struct Vector* vector);

int firstIndexOf(const struct Vector* vector, predicate p);

int lastIndexOf(const struct Vector* vector, predicate p);

void insert(struct Vector* vector, size_t index, float n);

void remove_element(struct Vector* vector, size_t index);