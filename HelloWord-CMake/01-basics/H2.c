#include <stdio.h>
#include <stdlib.h>

/**
 * Переставляет десятки и единицы в числе
 * @param number - входной параметр трехзначное число
 * @return число с переставленными десятками и единицами в числе
 */
int permutation(int number) {
    int b, c, d;
    b = number % 10;
    number /= 10;
    c = number % 10;
    number /= 10;
    d = number;
    return d * 100 + b * 10 + c;
}

int main(int argc, const char **argv) {
    int a;
    if (argc == 2) {
        a = atof(argv[1]);
    } else {
        puts("Введите трехзначное число: ");
        scanf("%i", &a);
    }
    printf("%i\n", permutation(a));
}