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

/**
 * Получение человека по ID
 * @param dataBase база данных
 * @param id идентификатор человека
 * @return возвращает человека, если человек с таикм ID имеется, иначе NULL
 */
struct Person* getPersonByID(const struct DataBase* const dataBase, const int id);

/**
 * Распечатает данные о человеке на консоль
 * @param dataBase указатель на базу данных
 * @param id идентификатор человека
 */
void printPerson(const struct DataBase *const dataBase,const  int id);

/**
 * Получение человека по индексу
 * @param dataBase база данных
 * @param index индекс человека
 * @return возвращает человека, если человек с таикм индексом имеется, иначе NULL
 */
struct Person* getPersonByIndex(struct DataBase* dataBase, const int index);

/**
 * Получение количества человек в базе данных
 * @param dataBase база данных
 * @return количество человек
 */
int getPersonCount(const struct DataBase* const dataBase);

/**
 * Добавление человека в базу данных
 * @param dataBase база данных
 * @param person указатель на человека
 */
void addPerson(struct DataBase* dataBase, struct Person* person);

/**
 * Удаление человека из базы данных
 * @param dataBase база данных
 * @param id идентификатор человека
 */
void removePerson(struct DataBase* dataBase, int id);

/**
 * Распечатать данные о человеке на консоль в сокращенном формате
 * @param person указатель на человека
 */
void printPersonBriefly(struct DataBase* dataBase);

/**
 * Открыть базу данных
 * @param pathToFile имя файла
 * @return указатель на базу данных
 */
struct DataBase* openDataBase(const char* pathToFile);

/**
 * Закрыть базу данных
 * @param dataBase указатель на базу данных
 */
void closeDataBase(struct DataBase* dataBase);
