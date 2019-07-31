#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, const char **argv) {
    system("chcp 65001");
    double a;
    double b;
    double c;
    double Im, Re;
    double x1, x2;
    if (argc == 4) {
        a = atof(argv[1]);
        b = atof(argv[2]);
        c = atof(argv[3]);
    }
    puts("Введите коэффициенты А, В, С: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    if (c == 0) {
        float x = -b / a;
        printf("Квадратное уравнение неполное, корни уравнения: x1 = 0, x2 = %lf", x);
    } else if (b == 0) {
        if ((a < 0 && c > 0) || (a > 0 && c < 0)) {
            x1 = sqrt(c / a);
            x2 = -sqrt(c / a);
            printf("Квадратное уравнение неполное, корни уравнения: x1 = %lf, x2 = %lf", x1, x2);
        } else {
            printf("Квадратное уравнение неполное, действительных корней уравнения нет");
        }
    } else if (b == 0 && c == 0) {
        printf("Квадратное уравнение неполное, корень уравнения: x = 0");
    } else {
        double D = pow(b, 2) - 4 * a * c;
        if (D == 0) {
            double x = -b / (2 * a);
            puts("Дискриминант = 0, один корень уравнения: ");
            printf("%lf", x);
        }
        if (D > 0) {
            double x1 = -(b + sqrt(D)) / (2 * a);
            double x2 = (-b - sqrt(D) / (2 * a));
            puts("Дискриминант > 0, два корня уравнения: x1 = ");
            printf("%lf", x1);
            puts("x2 = ");
            printf("%lf", x2);
        }
        if (D < 0) {
            Re = -b / (2 * a);
            Im = sqrt(-D) / (2 * a);
            printf("x1 = %g + i%g\n", Re, Im);
            printf("x2 = %g - i%g\n", Re, Im);
        }
    }
}
