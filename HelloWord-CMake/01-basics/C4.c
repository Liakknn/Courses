#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int check(int a, int b, int c) {
    if ((a + b > c) && (a + c > b) && (b + c > a)) {
        return 1;
    }
    return 0;
}

int main(int argc, const char **argv) {
    int a, b, c;
    if (argc == 4) {
        a = atoi(argv[1]);
        b = atoi(argv[2]);
        c = atoi(argv[3]);
    } else {
        puts("Введите стороны a, b, c: ");
        scanf("%i %i %i", &a, &b, &c);
    }
    if (check(a, b, c)) {
        puts("Треугольник невырожденный");
    } else {
        puts("Треугольник вырожденный");
    }
}
