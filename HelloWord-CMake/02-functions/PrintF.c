#include <stdio.h>
#include <math.h>
#include <stdarg.h>
void print_int(int number) {
	// находим количество цифр в числе
	int count = 0;
	if (number < 0) {
		putchar(45);
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
	int div = (int)pow(10, count - 1);
	for (int i = 0; i < count; ++i) {
		int digit = num / div;
		putchar(48 + digit);
		num %= div;
		div /= 10;
	}
}

void printF(const char* format, ...) {
	va_list args;
	va_start(args, format);
	for (int i = 0; format[i] != 0; ++i) {
		if (format[i] == '%' && (format[i + 1] == 'd' || format[i + 1] == 'i')) {
			print_int(va_arg(args, int));
			++i;
		}
		else {
			putchar(format[i]);
		}
	}
	va_end(args);
}

int main() {
	printF("Hello %i world %d", 56, 66);
}