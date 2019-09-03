#include <stdlib.h>
#include <stdio.h>

enum Type {
	FLAT,
	ROW,
	COLUMN,
	VIRTUAL
};

struct Matrix {
	void* data;
	enum Type type;
	size_t rows;
	size_t cols;
};

/**
 * Создание матрицы
 * @param type тип матрицы
 * @param rows количество строк
 * @param cols количество столбцов
 * @return указатель на матрицу
 */
struct Matrix* CreateMatrix(enum Type type, size_t rows, size_t cols);

/**
 * Установка нового значения в указанное место в матрице
 * @param matrix указатель на матрицу
 * @param row индекс строки
 * @param col индекс столбца
 * @param value новое значение
 */
void SetMatrixValue(struct Matrix* matrix, size_t row, size_t col, float value);

/**
 * Получение значения в матрице по указанному месту
 * @param matrix указатель на матрицу
 * @param row индекс строки
 * @param col индекс столбца
 * @return значение
 */
float GetMatrixValue(struct Matrix* matrix, size_t row, size_t col);

/**
 * Распечатать матрицу в указанный поток вывода
 * @param matrix указатель на матрицу
 * @param file указатель на поток вывода
 */
void PrintMatrix(struct Matrix* matrix, FILE* file);

/**
 * Освобождение памяти, выделенной под матрицу
 * @param matrix указатель на матрицу
 */
void DestroyMatrix(struct Matrix* matrix);

/**
 * Обмен местами двух строк из двух матриц
 * @param matrix1 указатель на первую матрицу
 * @param matrix2 указатель на вторую матрицу
 * @param indexRow1 индекс строки в первой матрице
 * @param indexRow2 индекс строки во второй матрице
 */
void SwapRows(struct Matrix* matrix1, struct Matrix* matrix2, size_t indexRow1, size_t indexRow2);
