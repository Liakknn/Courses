#pragma once
#include <stdio.h>

#define MAX_NAME_LENGTH 32

//unsigned int lastId = 0;

struct Person {
	int id;
	char lastName[MAX_NAME_LENGTH];
	char firstName[MAX_NAME_LENGTH];
	char middleName[MAX_NAME_LENGTH];
	unsigned char birthDay;
	unsigned char birthMonth;
	unsigned int birthYear;
};

struct Person* newPerson(
	const char* const lastName,
	const char* const firstName,
	const char* const middleName,
	const unsigned char birthDay,
	const unsigned char birthMonth,
	const unsigned int birthYear);

struct Person* getPersonByID(FILE* f, int id);
void printPerson(const struct Person *const person);
struct Person* getPersonByIndex(FILE* f, int number);
int getPersonCount(FILE* f);
void addPerson(FILE* f, const struct Person* person);
void removePerson(FILE** f, int id);
//unsigned int getId();
