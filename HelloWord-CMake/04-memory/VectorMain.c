#include "Vector.h"
#include <stdio.h>

bool is_even(float number) {	
	return (int)number % 2 == 0;
}

bool is_odd(float number) {
	return (int)number % 2;
}

int main() {
	struct Vector v1;
	struct Vector v2[3];
	struct Vector* v3 = (struct Vector*)malloc(sizeof(struct Vector));
	struct Vector* v4 = (struct Vector*)malloc(3 * sizeof(struct Vector));
	vector_init(&v1, 1);
	vector_init(v2, 2);
	vector_init(v2 + 1, 3);// &*(v2 + 1)=
	vector_init(v2 + 2, 4);
	vector_init(v3, 5);
	vector_init(v4, 6);
	vector_init(v4 + 1, 7);
	vector_init(v4 + 2, 8);
	//vector_print(&v1);
	//vector_print(v2);
	//vector_print(v2 + 1);
	//vector_print(v2 + 2);
	//vector_print(v3);
	//vector_print(v4);
	//vector_print(v4 + 1);
	//vector_print(v4 + 2);
	printf("%i\n", firstIndexOf(v3, is_odd));
	printf("%i\n", lastIndexOf(v4, is_even));
	insert(&v1 ,1, 2.00);
	//vector_print(&v1);
	remove_element(v4 + 1, 0);
	//vector_print(v4 + 1);
	vector_free(&v1);
	vector_free(v2);
	vector_free(v3);
	vector_free(v4);
	vector_print(v4+1);
}