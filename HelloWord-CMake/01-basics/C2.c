#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

int permutation(int number) {
    int b, c, d;
    b = number % 10;
    number /= 10;
    c = number % 10;
    number /= 10;
    d = number;
    return c * 100 + d * 10 + b;
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