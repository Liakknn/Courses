#include "person.h"
#include <stdlib.h>

int main() {
	struct Person* person1 = newPerson("Иванов", "Данила", "Иванович", 23, 5, 2000);
	struct Person* person2 = newPerson("Алексеева", "Лиза", "туц", 23, 5, 2000);
	FILE* f = fopen("data", "w+");
	addPerson(f, person1);
	addPerson(f, person2);
	printPerson(person1);
	struct Person* p3=getPersonByID(f,person1->id);
	printPerson(p3);
	removePerson(f,person1->id);
	fclose(f);
	free(person1);
	free(person2);
}