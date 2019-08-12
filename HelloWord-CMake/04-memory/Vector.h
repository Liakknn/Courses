#include<stdlib.h>

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