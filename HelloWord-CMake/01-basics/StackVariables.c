#include <stdio.h>

int main() {
	int a = 0; 
	int b = 1; 
	int c = 2;
	printf("%lu %lu %lu\n", (unsigned long)(unsigned long long) &a, (unsigned long)(unsigned long long) &b,
	        (unsigned long)(unsigned long long) &c);
	printf("%d %d %d\n", a, b, c);
	int* d = &b - 8;
	*d = 5;
	int* r = &b + 8;
	*r = 10;
	printf("%d %d %d\n", a, b, c);
}
