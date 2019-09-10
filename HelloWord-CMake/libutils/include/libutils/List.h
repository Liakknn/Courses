#include <stdio.h>

struct List;
struct List* add(struct List** head, int data);
void removeList(struct List** head, struct List* node);
size_t count(struct List* head);
struct List* find(struct List*, int data);
void set_list(struct List* head, int data);
int get_list(struct List* head);
void list_print(struct List *head);
