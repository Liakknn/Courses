#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/**
 * Проверяет невырожденность треугольника. Возращает 1, если треугольник невырожденный.
 * Возвращает 0, если треугольник вырожденнный.
 * @param a сторона треугольника
 * @param b сторона треугольника
 * @param c сторона треугольника
 * @return 1 - если треугольник невырожденный, 0 - иначе.
 */
int isDegenerateTriangle(const double a, const double b, const double c) {
    if ((a + b > c) && (a + c > b) && (b + c > a)) {
        return 1;
    }
    return 0;
}

int main(int argc, const char **argv) {
    int a, b, c;
    if (argc == 4) {
        a = atof(argv[1]);
        b = atof(argv[2]);
        c = atof(argv[3]);
    } else {
        puts("Введите стороны a, b, c: ");
        scanf("%i %i %i", &a, &b, &c);
    }
    if (check(a, b, c)) {
        puts("Треугольник невырожденный");
    } else {
        puts("Треугольник вырожденный");
    }
}
