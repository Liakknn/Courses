#include "person.h"
#include <stdlib.h>
#include <string.h>

struct DataBase {
    FILE* file;
    char* pathToFile;
};

struct Person* newPerson(const char* const lastName,
	const char* const firstName,
	const char* const middleName,
	unsigned char const birthDay,
	unsigned char const birthMonth,
	unsigned int const birthYear) {
	struct Person* const person = (struct Person*)calloc(1, sizeof(*person));
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
    printf(".\n");
}

struct Person* getPersonByID(struct DataBase* dataBase, int id) {
    struct Person *const person = (struct Person *) malloc(sizeof(struct Person));
    size_t count = getPersonCount(dataBase);
    for (size_t i = 0; i < count; ++i) {
        fseek(dataBase->file, i * sizeof(struct Person), SEEK_SET);
        fread(person, sizeof(struct Person), 1, dataBase->file);
        if (person->id == id) {
            return person;
        }
    }
    free(person);
    return NULL;
}

struct Person* getPersonByIndex(struct DataBase* dataBase, const int index) {
    fseek(dataBase->file, 0, SEEK_END);
    size_t count = ftell(dataBase->file) / sizeof(struct Person);
    if((size_t )index >= count) {
        return NULL;
    }
	struct Person* const person = (struct Person*)malloc(sizeof(*person));
	fseek(dataBase->file, sizeof(struct Person) * index, SEEK_SET);
	fread(person, sizeof(struct Person), 1, dataBase->file);
	return person;
}

int getPersonCount(struct DataBase* dataBase) {
	fseek(dataBase->file, 0, SEEK_END);
	return ftell(dataBase->file) / sizeof(struct Person);
}

int maxId(struct DataBase* dataBase) {
    size_t maxId = 0;
    fseek(dataBase->file, 0, SEEK_END);
    size_t count = getPersonCount(dataBase);
    struct Person *const person = (struct Person *) malloc(sizeof(struct Person));
    for (size_t i = 0; i < count; ++i) {
        fseek(dataBase->file, i * sizeof(struct Person), SEEK_SET);
        fread(person, sizeof(struct Person), 1, dataBase->file);
        if ((size_t) person->id > maxId) {
            maxId = person->id;
        }
    }
    free(person);
    return maxId + 1;
}

void addPerson(struct DataBase* dataBase, struct Person* const person) {
    person->id = maxId(dataBase);
	fseek(dataBase->file, 0, SEEK_END);
	fwrite(person, sizeof(struct Person), 1, dataBase->file);
}

void removePerson(struct DataBase* dataBase, int const id) {
    fseek(dataBase->file, 0, SEEK_END);
    size_t size = ftell(dataBase->file);
    struct Person* person = (struct Person*) malloc(size);
    size_t count = size / sizeof(struct Person);
    fseek(dataBase->file, 0, SEEK_SET);
    fread(person, sizeof(struct Person), count, dataBase->file);
    fclose(dataBase->file);
    dataBase->file = freopen(dataBase->pathToFile, "w+", dataBase->file);
    perror("");
    for(struct Person* p = person; p < person + count; ++p) {
        if (p->id != id) {
            fwrite(p, sizeof(struct Person), 1, dataBase->file);
        }
    }
    free(person);
}

struct DataBase* openDataBase(const char* pathToFile) {
    struct DataBase* dataBase = malloc(sizeof(struct DataBase));
    dataBase->pathToFile = malloc(strlen(pathToFile) + 1);
    strcpy_s(dataBase->pathToFile, strlen(pathToFile) + 1, pathToFile);
    dataBase->file = fopen(pathToFile, "w+");
    return dataBase;
}

void closeDataBase(struct DataBase* dataBase) {
    fclose(dataBase->file);
    free(dataBase->pathToFile);
    free(dataBase);
}