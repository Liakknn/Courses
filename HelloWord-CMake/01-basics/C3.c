#include <stdio.h>

/**
 * Вычисляет количество секунд, прошедших с последнего часа.
 * @param count количество секунд
 * @return количество секунд, прошедших с последнего часа.
 */
int secondsFromLastHour(int seconds) {
    return seconds % 3600;
}

int main(int argc, const char **argv) {
    int count;
    if (argc == 2) {
        count = atoi(argv[1]);
    } else {
        puts("Введите количество секунд: ");
        scanf("%i", &count);
    }
    printf("\nПрошло секунд с последнего часа: %i", secondsFromLastHour(count));
}