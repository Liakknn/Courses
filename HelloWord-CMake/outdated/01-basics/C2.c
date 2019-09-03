#include <stdio.h>
#include <stdlib.h>

/**
 * Переставляет сотни и десятки в числе.
 * @param number принимаемое число
 * @return возвращает число с переставленными сотнями и десятками.
 */
int permutationOfHundreadAndTensInNumber(int number) {
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
        return decades * 100 + hundred * 10 + unit;
    }
    else {
        return number;
    }
}

int main(int argc, const char **argv) {
    int a;
    if (argc == 2) {
        a = atof(argv[1]);
    } else {
        puts("Введите трехзначное число: ");
        scanf("%i", &a);
    }
    printf("%i\n", permutationOfHundreadAndTensInNumber(a));
}