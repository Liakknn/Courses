#include <stdlib.h>
#include <stdio.h>

void print(int* n, char* schar, char* dchar) {
	printf("Address     n: %lu, as int: %12i, as string: '%s'\n", (unsigned long)(unsigned long long) n, *n, (char*) n);
	printf("Address schar: %lu, as int: %12i, as string: '%s'\n", (unsigned long)(unsigned long long) schar, *((int*) schar), schar);
	printf("Address dchar: %lu, as int: %12i, as string: '%4s'\n", (unsigned long)(unsigned long long) dchar, *((int*)dchar), dchar);
}

int main() {
	int n = 0;
	char schar[4] = { 0 };
	char* dchar = calloc(4, 1);
	char* ptr = (char*) &n;
	int* sint = (int*) schar;
	int* dint = (int*)(*(&dchar));
	print(&n, schar, dchar);

	n = 0x656854;
	*sint = (48 << 16) + (48 << 8) + 49;
	*dint = (33 << 8) + 63;
	print(&n, schar, dchar);

	//
	ptr[0] = 100;
	ptr[1] = 0;
	ptr[2] = 0;
	ptr[3] = 0;
	schar[0] = 0xE3;
	schar[1] = 0x7;
	schar[2] = 0;
	schar[3] = 0;
	const int number = 987654321;
	dchar[0] = number & 0xFF;
	dchar[1] = (number & 0xFF00) >> 8;
	dchar[2] = (number & 0xFF0000) >> 16;
	dchar[3] = (number & 0xFF000000) >> 24;
	print(&n, schar, dchar);
}