#include<stdlib.h>

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