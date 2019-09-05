#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Вычисление факториала.
 * @param n число для которого надо вычислить факториал.
 * @return факториал числа.
 */
double factorial(double n) {
    if (n == 1 || n == 0) return 1;
    double factorial = 1;
    for (int i = 0; i < n; ++i) {
        factorial *= n;
    }
    return factorial;
}

/**
 * Вычисление экспоненты в точке x, с помощью первых countElements членов ряда Тейлора.
 * @param x значение в точке.
 * @param countElements количество элементов ряда Тейлора.
 * @return сумму ряда Тейлора.
 */
double my_exp(const double x, const int countElements) {
    double s = 0;
    for (int i = 0; i < countElements; ++i) {
        s += pow(x, countElements) / factorial(countElements);
    }
    return s; // когда вышли из цикла - вернем результат
}

int main(int argc, const char **argv) {
    double x;
    int countElements;
    if (argc == 3) {
        x = atof(argv[1]);
        countElements = atoi(argv[2]);
    } else {
        puts("Введите значение x и количество элементов");
        scanf("%lf %i", &x, &countElements);
    }
    printf("%f", my_exp(x, countElements));
}