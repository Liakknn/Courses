#include <stdio.h>
#include <math.h>
#include <stdarg.h>
#include <ctype.h>

void print_double(double number, int accuracy) {
    if (number < 0) {
        putchar('-');
        number = -number;
    }
    double whole = 0;
    modf(number, &whole);
    double fractional = number - whole;
    int countWhole = 0;
    {
        int num = number;
        if (num == 0) {
            ++countWhole;
        }
        while (num != 0) {
            num /= 10;
            ++countWhole;
        }
    }
    int num = number;
    int divWhole = (int) pow(10, countWhole - 1);
    for (int i = 0; i < countWhole; ++i) {
        int digit = num / divWhole;
        putchar(48 + digit);
        num %= divWhole;
        divWhole /= 10;
    }
    putchar('.');
    int divFractional = (int) pow(10, accuracy);
    int dig = fractional * divFractional;
    divFractional /= 10;
    for (int i = 0; i < accuracy; ++i) {
        int digit = dig / divFractional;
        putchar('0' + digit);
        dig %= divFractional;
        divFractional /= 10;
    }
}

void print_int(int number) {
    // находим количество цифр в числе
    int count = 0;
    if (number < 0) {
        putchar('-');
        number = -number;
    }
    {
        int num = number;
        if (num == 0) {
            ++count;
        }
        while (num != 0) {
            num /= 10;
            ++count;
        }
    }
    //вывод числа на экран
    int num = number;
    int div = (int) pow(10, count - 1);
    for (int i = 0; i < count; ++i) {
        int digit = num / div;
        putchar(48 + digit);
        num %= div;
        div /= 10;
    }
}

void printF(const char *format, ...) {
    va_list args;
    va_start(args, format);
    for (int i = 0; format[i] != 0; ++i) {
        if (format[i] == '%' && (format[i + 1] == 'd' || format[i + 1] == 'i')) {
            print_int(va_arg(args, int));
            ++i;
        }
        /* if(format[i] == '%' && (format[i + 1] == 'c' || (format[i + 1] == 'h' && format[i + 2] == 'h' && format[i + 3] == 'i'))) {
           print_int(va_arg(args, char));
           ++i;
       } */

        if (format[i] == '%' && isdigit(format[i + 1]) && format[i + 2] == 'f') {
            print_double(va_arg(args, double), '0' + format[i + 1]);
        } else {
            putchar(format[i]);
        }
    }
    va_end(args);
}

int main() {
    print_double(1243.1456, 3);
    printF("Hello %2f world", 2.1234);
}