#include<stdlib.h>
#include <stdbool.h>

typedef bool (*predicate) (float);

/**—труктура с динамическим массивом float
 *
 */
struct Vector {
	float* data;   /*< указатель на данные */
	size_t capacity;  /*< количество элементов под которые выделена пам€ть */
	size_t size;      /*< реальное количество элементов */
};

/**
 * »ницилизирует указатель vector
 * @param vector указатель на структуру Vector, не должен быть равен NULL
 * @param n количество элементов
 */
void vector_init(struct Vector* vector, size_t n);

/**
 * ќсвобождает пам€ть, выделенную под vector
 * @param vector указатель на vector
 */
void vector_free(struct Vector* vector);

/**
 * ѕечатает на консоль vector
 * @param vector указатель на vector
 */
void vector_print(const struct Vector* vector);

/**
 * Ќаходит индекс первого элемента, который выпол€ет заданное условие
 * @param vector указатель на vector
 * @param p предикат
 * @return индекс элемента
 */
int firstIndexOf(const struct Vector* vector, predicate p);

/**
 * Ќаходит индекс последнего элемента, который выпол€ет заданное условие
 * @param vector указатель на vector
 * @param p предикат
 * @return индекс элемента
 */
int lastIndexOf(const struct Vector* vector, predicate p);

/**
 * ¬ставка значени€ на заданное место в vector
 * @param vector указатель на vector
 * @param index индекс элемента, на место которого нужно поставить новое значение
 * @param n новое значение
 */
void insert(struct Vector* vector, size_t index, float n);

/**
 *”даление элемента из vector по заданному индексу
 * @param vector указатель на vector
 * @param index индекс элемента, который нужно удалить из vector
 */
void remove_element(struct Vector* vector, size_t index);