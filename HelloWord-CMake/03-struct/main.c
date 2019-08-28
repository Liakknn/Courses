#include "person.h"
#include <stdlib.h>

int main() {

	struct Person* person1 = newPerson("Ivanov", "Danila", "Aleksandrovich", 23, 5, 2000);
	struct Person* person2 = newPerson("Alekseeva", "Elizaveta", "Alekseevna", 23, 5, 2000);
	struct DataBase* dataBase = openDataBase("data");
	addPerson(dataBase, person1);
	addPerson(dataBase, person2);
	printf("0 -  �������� ���� ���� � ����������� ������� (id, �������, ��������);\n"
        "1 - �������� ���� ���������� � �������� �� ���������� id;\n"
        "2 - ���������� ������ �������� � ���� ������;\n"
        "3 - �������� �������� �� ���� ������.\n"
        "����� ������ ����� - �������� ����\n");
	while(1) {
        printf("������� �������:");
        int number;
        scanf("%d", &number);
        switch(number) {
            case 0: {
                printPersonBriefly(dataBase);
                break;
            }
            case 1: {
                printf("������� ID:");
                int id;
                scanf("%d", &id);
                printPerson(dataBase, id);
                break;
            }
            case 2: {
                printf("������� �������: ");
                char F[MAX_NAME_LENGTH];
                scanf("%s", F);
                printf("������� ���: ");
                char I[MAX_NAME_LENGTH];
                scanf("%s", I);
                printf("������� ��������: ");
                char O[MAX_NAME_LENGTH];
                scanf("%s", O);
                printf("������� ���� ��������: ");
                char birthD[2];
                scanf("%s", birthD);
                printf("������� ����� ��������: ");
                char birthM[2];
                scanf("%s", birthM);
                printf("������� ��� ��������: ");
                int birthY;
                scanf("%d", &birthY);
                struct Person* p = newPerson(F, I, O, (unsigned char) birthD, (unsigned char) birthM, birthY);
                addPerson(dataBase, p);
                free(p);
                break;
            }
            case 3: {
                printf("������� ID ��������, ��� �������� �� ���� ������: ");
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


