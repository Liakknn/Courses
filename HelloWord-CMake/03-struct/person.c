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
	person->id = 0;
    return person;
}

//unsigned int getId() {
//    return ++lastId;
//}

void printPerson(const struct Person *const person) {
    printf("ID:%d\n", person->id);
    printf("Birthday: %d.%d.%d\n", person->birthDay, person->birthMonth, person->birthYear);
    printf("Last Name: %s\nFirst Name: %s\nMiddle Name: %s\n", person->lastName, person->firstName, person->middleName);
}

void printPersonBriefly(const struct Person* const person) {
    printf("%d ", person->id);
    printf("%s ", person->lastName);
    putchar(person->firstName[0]);
    printf(". ");
    putchar(person->middleName[0]);
    printf(".");
}

struct Person* getPersonByID(FILE* f, int id) {
    struct Person *const person = (struct Person *) malloc(sizeof(struct Person));
    size_t count = getPersonCount(f);
    for (size_t i = 0; i < count; ++i) {
        fseek(f, i * sizeof(struct Person), SEEK_SET);
        fread(person, sizeof(struct Person), 1, f);
        if (person->id == id) {
            free(id);
            return person;
        }
    }
    return NULL;
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

void addPerson(FILE* f, struct Person* const person) {
    person->id = lastId + 1;
	fseek(f, 0, SEEK_END);
	fwrite(person, sizeof(struct Person), 1, f);
}

void removePerson(FILE** f, int const id) {
    fseek(f, 0, SEEK_END);
    size_t count = getPersonCount(f);
    struct Person* person = (struct Person*) malloc(count * sizeof(struct Person*));
    fread(person, sizeof(struct Person), count, f);
    fclose(f);
    fopen(f, "w+");
    for(int i = 0; i < count; ++i) {
        fseek(f, i * sizeof(struct Person), SEEK_SET);
        if(person->id != id) {
            fread(f, sizeof(struct Person), 1, person);
        }
    }
}