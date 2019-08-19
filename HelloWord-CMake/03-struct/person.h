#pragma once
#include <stdio.h>

#define MAX_NAME_LENGTH 32

struct Person {
	int id;
	char lastName[MAX_NAME_LENGTH];
	char firstName[MAX_NAME_LENGTH];
	char middleName[MAX_NAME_LENGTH];
	unsigned char birthDay;
	unsigned char birthMonth;
	unsigned int birthYear;
};

struct DataBase;

struct Person* newPerson(
	const char* const lastName,
	const char* const firstName,
	const char* const middleName,
	const unsigned char birthDay,
	const unsigned char birthMonth,
	const unsigned int birthYear);

struct Person* getPersonByID(struct DataBase* dataBase, int id);
void printPerson(const struct Person *const person);
struct Person* getPersonByIndex(struct DataBase* dataBase, int number);
int getPersonCount(struct DataBase* dataBase);
void addPerson(struct DataBase* dataBase, struct Person* person);
void removePerson(struct DataBase* dataBase, int id);
void printPersonBriefly(const struct Person* const person);
struct DataBase* openDataBase(const char* pathToFile);
void closeDataBase(struct DataBase* dataBase);
