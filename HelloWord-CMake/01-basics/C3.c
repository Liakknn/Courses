#include <stdio.h>
#include <windows.h>

int countSeconds(int count) {
    int countHours = count / 3600;
    return count - countHours * 3600;
}

int main(int argc, const char **argv) {
    system("chcp 65001");
    int count;
    if (argc == 2) {
        count = atoi(argv[1]);
    } else {
        puts("Введите количество секунд: ");
        scanf("%i", &count);
    }
    puts("\nПрошло секунд с последнего часа: ");
    printf("%i", countSeconds(count));
}