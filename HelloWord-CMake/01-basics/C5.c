#include <stdio.h>
#include <stdlib.h>
double pow(double x, double y);

/**
 * Вычисляет значение функции для заданного вещественного x.
 * @param x - входной параметр вещественное число
 * @return значение функции
 */
double valueFunction(double const x) {
    if(x <= 0) {
        return -x;
    }
    else if(0 < x && x < 2) {
        return pow(x, 2);
    }
    else {
        return 4;
    }
}

int main(int argc, const char **argv) {
    double x;
    if(argc == 2) {
        x = atof(argv[1]);
    }
    puts("Введите x");
    scanf("%lf", &x);
    printf("%lf", valueFunction(x));
}