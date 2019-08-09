#include <math.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, const char *argv[]) {
    double x1, y1, z1, x2, y2, z2;
    if (argc == 7) {
        x1 = atof(argv[1]);
        x2 = atof(argv[2]);
        y1 = atof(argv[3]);
        y2 = atof(argv[4]);
        z1 = atof(argv[5]);
        z2 = atof(argv[6]);
    }
        puts("Введите координаты точек: x1 y1 z1 x2 y2 z2");
        scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &z1, &x2, &y2, &z2);
        float distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2) + pow((z2 - z1), 2));
        printf("%lf\n", distance);
}