#include <stdio.h>
#include <stdlib.h>

/**
 * Вычисляет количество дней в году.
 * @param year - входной параметр год
 * @return количество дней
 */
int countDays(int year) {
    if (year <= 0) {
        return 0;
    }
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return 366;
    } else {
        return 365;
    }
}



int main(int argc, const char **argv) {
    int year;
    if (argc == 2) {
        year = atof(argv[1]);
    }
    puts("Введите год: ");
    scanf("%i", &year);
    printf("Количество дней в году: %i", countDays(year));
}
