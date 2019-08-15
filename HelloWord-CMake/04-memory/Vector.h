#include<stdlib.h>
#include <stdbool.h>

typedef bool (*predicate) (float);

/** ��������� ��� ������ � ������������ �������� float
*/
struct Vector {
	float* data;   /*< ��������� �� ������ */
	size_t capacity;  /*< ���������� ��������� ��� ������� �������� ������ */
	size_t size;      /*< �������� ���������� ��������� */
};

/**�������������� ��������� vector
@param vector ��������� �� ��������� Vector, �� ������ ���� ����� NULL
@param n ���������� ��������� 
*/

void vector_init(struct Vector* vector, size_t n);

void vector_print(const struct Vector* vector);

int firstIndexOf(const struct Vector* vector, predicate p);

int lastIndexOf(const struct Vector* vector, predicate p);

void insert(struct Vector* vector, size_t index, float n);

void remove_element(struct Vector* vector, size_t index);