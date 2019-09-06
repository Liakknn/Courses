#include<stdlib.h>
#include <stdbool.h>

typedef bool (*predicate) (float);

/**��������� � ������������ �������� float
 *
 */
struct Vector {
	float* data;   /*< ��������� �� ������ */
	size_t capacity;  /*< ���������� ��������� ��� ������� �������� ������ */
	size_t size;      /*< �������� ���������� ��������� */
};

/**
 * ������������� ��������� vector
 * @param vector ��������� �� ��������� Vector, �� ������ ���� ����� NULL
 * @param n ���������� ���������
 */
void vector_init(struct Vector* vector, size_t n);

/**
 * ����������� ������, ���������� ��� vector
 * @param vector ��������� �� vector
 */
void vector_free(struct Vector* vector);

/**
 * �������� �� ������� vector
 * @param vector ��������� �� vector
 */
void vector_print(const struct Vector* vector);

/**
 * ������� ������ ������� ��������, ������� �������� �������� �������
 * @param vector ��������� �� vector
 * @param p ��������
 * @return ������ ��������
 */
int firstIndexOf(const struct Vector* vector, predicate p);

/**
 * ������� ������ ���������� ��������, ������� �������� �������� �������
 * @param vector ��������� �� vector
 * @param p ��������
 * @return ������ ��������
 */
int lastIndexOf(const struct Vector* vector, predicate p);

/**
 * ������� �������� �� �������� ����� � vector
 * @param vector ��������� �� vector
 * @param index ������ ��������, �� ����� �������� ����� ��������� ����� ��������
 * @param n ����� ��������
 */
void insert(struct Vector* vector, size_t index, float n);

/**
 *�������� �������� �� vector �� ��������� �������
 * @param vector ��������� �� vector
 * @param index ������ ��������, ������� ����� ������� �� vector
 */
void remove_element(struct Vector* vector, size_t index);

void vector_print(const struct Vector *vector);