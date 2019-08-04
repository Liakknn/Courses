#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

/**
 * Переставляет сотни и десятки в числе.
 * Возвращает число с переставленными сотнями и десятками.
 * @param unit - цифра единиц в трехзначном числе
 * @param decades - цифра десятков в трехзначном числе
 * @param hundred - цифра сотен в трехзначном числе
 * @param number - принимаемое число
 */
int permutation(int number) {
    int unit, decades, hundred;
    unit = number % 10;
    number /= 10;
    decades = number % 10;
    number /= 10;
    hundred = number;
    return decades * 100 + hundred * 10 + unit;
}

int main(int argc, const char **argv) {
    system("chcp 65001");
    int a;
    if (argc == 2) {
        a = atof(argv[1]);
    } else {
        puts("Введите трехзначное число: ");
        scanf("%i", &a);
    }
    printf("%i\n", permutation(a));
}