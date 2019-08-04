#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char **argv) {
    int a, b;
    if(argc == 3) {
        a = atof(argv[1]);
        b = atof(argv[2]);
    }
    puts("Введите A, B (A < B)");
    scanf("%i %i", &a, &b);
    if(a >= b) {
        puts("Введите A, B, удовлетворяющие условию A < B");
    }
    else {
        int count = 1;
        for (int i = a; i <= b; i++, count++) {
            for (int j = 0; j < count; j++) {
                printf("%i ", i);
            }
        }
    }
}