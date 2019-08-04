#include <stdio.h>
#include <stdlib.h>

/**
 * Вычисляет наибольший общий делитель двух чисел.
 * @param a - входной параметр первое число
 * @param b - входной параметр второе число
 * @return наибольший общий делитель чисел a, b
 */
int nod(int a, int b) {
    if (a < 0 || b < 0) {
        return 0;
    }
    while (a > 0 && b > 0)
        if (a > b)
            a %= b;
        else
            b %= a;
    return a + b;

}

int main(int argc, const char **argv) {
    int a, b;
    if (argc == 3) {
        a = atof(argv[1]);
        b = atof(argv[2]);
    }
    puts("Введите A, B ");
    scanf("%i %i", &a, &b);
    printf("Наибольший общий делитель: %i", nod(a, b));
}

