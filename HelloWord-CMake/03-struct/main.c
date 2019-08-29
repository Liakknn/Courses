#include "person.h"
#include <stdlib.h>

int main() {

	struct Person* person1 = newPerson("Ivanov", "Danila", "Aleksandrovich", 23, 5, 2000);
	struct Person* person2 = newPerson("Alekseeva", "Elizaveta", "Alekseevna", 23, 5, 2000);
	struct DataBase* dataBase = openDataBase("data");
	addPerson(dataBase, person1);
	addPerson(dataBase, person2);
	printf("0 -  просмотр всей базы в сокращённом формате (id, фамилия, инициалы);\n"
        "1 - просмотр всей информации о человеке по указанному id;\n"
        "2 - добавление нового человека в базу данных;\n"
        "3 - удаление человека из базы данных.\n"
        "любая другая цифра - закрытие меню\n");
	while(1) {
        printf("Введите команду:");
        int number;
        scanf("%d", &number);
        switch(number) {
            case 0: {
                printPersonBriefly(dataBase);
                break;
            }
            case 1: {
                printf("Введите ID:");
                int id;
                scanf("%d", &id);
                printPerson(dataBase, id);
                break;
            }
            case 2: {
                printf("Введите фамилию: ");
                char F[MAX_NAME_LENGTH];
                scanf("%s", F);
                printf("Введите имя: ");
                char I[MAX_NAME_LENGTH];
                scanf("%s", I);
                printf("Введите отчество: ");
                char O[MAX_NAME_LENGTH];
                scanf("%s", O);
                printf("Введите день рождения: ");
                char birthD[2];
                scanf("%s", birthD);
                printf("Введите месяц рождения: ");
                char birthM[2];
                scanf("%s", birthM);
                printf("Введите год рождения: ");
                int birthY;
                scanf("%d", &birthY);
                struct Person* p = newPerson(F, I, O, (unsigned char) birthD, (unsigned char) birthM, birthY);
                addPerson(dataBase, p);
                free(p);
                break;
            }
            case 3: {
                printf("Введите ID человека, для удаления из базы данных: ");
                int id;
                scanf("%d", &id);
                removePerson(dataBase, id);
                break;
            }
            default:
                goto Exit;
        }
    }
    Exit:
    closeDataBase(dataBase);
    free(person1);
    free(person2);
}


