#include <stdio.h>
#include <stdlib.h>

/**
 * Вычисляет количество квадратов, которое поместиться в прямоугольнике размером a на b.
 * @param a сторона прямоугольника
 * @param b сторона прямоугольника
 * @param c сторона квадрата
 * @return количество квадратов, которое помещается в прямоугольнике.
 */
int countSquares(int a, int b, int c) {
    // Кол-во квадратов по вертикали
    int vertCount = 0;
    while (b >= c)
    {
        b -= c;
        vertCount++;
    }
    // Кол-во по горизонтали
    int horzCount = 0;
    while (a >= c)
    {
        a -= c;
        horzCount++;
    }
    int result = 0;
    for (int i = 0; i < vertCount; i++)
    {
        result += horzCount;
    }
    return result;
}

/**
 * Ищется количество квадратов, которое уместиться на прямоугольнике. Затем вычисляется площаль незанятой части.
 * @param a сторона прямоугольника
 * @param b сторона прямоугольника
 * @param c сторона квадрата
 * @return площадь незанятой части
 */
int countArea(int a, int b, int c) {
    int result = a * b - c * c * countSquares(a, b, c);
    return result;
}

int main(int argc, const char **argv) {
    int a, b, c;
    if(argc == 4) {
        a = atof(argv[1]);
        b = atof(argv[2]);
        c = atof(argv[3]);
    }
    puts("Введите A, B, C");
    scanf("%i %i %i", &a, &b, &c);
    printf("Количество квадратов: %i\n", countSquares(a, b, c));
    printf("Незанятая площадь: %i", countArea(a, b, c));
}