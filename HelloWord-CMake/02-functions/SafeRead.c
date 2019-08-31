#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>

int read_int(const char *prompt, int min, int max) {
    while (true) {
        printf("%s", prompt);
        char buf[16];
        fgets(buf, sizeof(buf), stdin);
        if (strchr(buf, '\n') == NULL) {
            int ch;
            bool flag = true;
            while ((ch = fgetc(stdin)) != '\n' && ch != EOF) {
                if (!isspace(ch)) {
                    flag = false;
                }
            }
            if (flag == false) {
                printf("Введенная строка превышает допустимый размер!\n");
                continue;
            }
        }
        char *endptr = NULL;
        errno = 0;
        int l = strtol(buf, &endptr, 10);
        int tmp = errno;
        if (buf == endptr) {
            printf("Введенная строка - не число!\n");
            continue;
        }
        bool flag = true;
        for (char *p = endptr; *p != '\0'; ++p) {
            if (!isspace(*p)) {
                flag = false;
                break;
            }
        }
        if (!flag) {
            printf("Введенная строка  - не число!\n");
            continue;
        }
        if (tmp == ERANGE) {
            printf("Строка выходит за допустимые пределы!\n");
            continue;
        }
        if (l >= min && l <= max) {
            return l;
        } else {
            printf("Выход за границы ожидаемого диапазона[%d; %d].\n", min, max);
        }
    }
}

double read_double(const char *prompt, double min, double max) {
    while (true) {
        printf("%s", prompt);
        char buf[32];
        fgets(buf, sizeof(buf), stdin);
        if (strchr(buf, '\n') == NULL) {
            double ch;
            bool flag = true;
            while ((ch = fgetc(stdin)) != '\n' && ch != EOF) {
                if (!isspace(ch)) {
                    flag = false;
                }
            }
            if (flag == false) {
                printf("Введенная строка превышает допустимый размер!\n");
                continue;
            }
        }
        char *endptr = NULL;
        errno = 0;
        double l = strtod(buf, &endptr);
        int tmp = errno;
        if (buf == endptr) {
            printf("Введенная строка - не число!\n");
            continue;
        }
        bool flag = true;
        for (char *p = endptr; *p != '\0'; ++p) {
            if (!isspace(*p)) {
                flag = false;
                break;
            }
        }
        if (!flag) {
            printf("Введенная строка  - не число!\n");
            continue;
        }
        if (tmp == ERANGE) {
            printf("Строка выходит за допустимые пределы!\n");
            continue;
        }
        if (l >= min && l <= max) {
            return l;
        } else {
            printf("Выход за границы ожидаемого диапазона[%g; %g].\n", min, max);
        }
    }
}

int main() {
    int i = read_int("Введите n: ", -100, 100);
    printf("Успешно: %d\n", i);
    double j = read_double("Введите число: ", -100.55, 100.66);
    printf("успешно: %g\n", j);
}