#include "person.h"
#include <stdlib.h>

int main() {
	struct Person* person1 = newPerson("������", "������", "��������", 23, 5, 2000);
	struct Person* person2 = newPerson("���������", "����", "���", 23, 5, 2000);
	FILE* f = fopen("data", "w+");
	addPerson(f, person1);
	addPerson(f, person2);
	fclose(f);
	free(person1);
	free(person2);
}