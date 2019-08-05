#include "person.h"
#include <stdlib.h>
#include <string.h>

struct Person* newPerson(const char* const lastName,
	const char* const firstName,
	const char* const middleName,
	unsigned char const birthDay,
	unsigned char const birthMonth,
	unsigned int const birthYear) {
	struct Person* const person = (struct Person*)malloc(sizeof(*person));
	if (person == NULL) {
		return NULL;
	}
	strncpy_s(person->lastName, MAX_NAME_LENGTH, lastName, strlen(lastName));
	strncpy_s(person->firstName, MAX_NAME_LENGTH, firstName, strlen(firstName));
	strncpy_s(person->middleName, MAX_NAME_LENGTH, middleName, strlen(middleName));
	person->birthDay = birthDay;
	person->birthMonth = birthMonth;
	person->birthYear = birthYear;

}


struct Person* getPersonByID(FILE* f, int id) {
	
}

struct Person* getPersonByIndex(FILE* f, const int index) {
	struct Person* const person = (struct Person*)malloc(sizeof(*person));
	fseek(f, sizeof(struct Person) * index, SEEK_SET);
	fread(person, sizeof(struct Person), 1, f);
	return person;
}

int getPersonCount(FILE* f) {
	fseek(f, 0, SEEK_END);
	return ftell(f) / sizeof(struct Person);
}

void addPerson(FILE* f, const struct Person* const person) {
	fseek(f, 0, SEEK_END);
	fwrite(person, sizeof(struct Person), 1, f);
}

void removePerson(FILE* f, int const id) {

}