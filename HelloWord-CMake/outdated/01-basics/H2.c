#include <stdio.h>
#include <stdlib.h>

/**
 * Переставляет десятки и единицы в числе
 * @param number трехзначное число
 * @return число с переставленными десятками и единицами в числе
 */
int permutation(int number) {
    int count = 0;
    while (number > 0) {
        number /= 10;
        ++count;
    }
    if (count == 3) {
        const int unit = number % 10;
        number /= 10;
        const int decades = number % 10;
        number /= 10;
        const int hundred = number;
        return d * 100 + b * 10 + c;
    }
    return number;
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