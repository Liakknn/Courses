#include <libutils/List.h>
#include <stdlib.h>

struct List {
    int data;
    struct  List* prev;
    struct List* next;
};

void set_list(struct List* head, int data){
    head->data = data;
}

int get_list(struct List* head) {
    return head->data;
}

struct List* add(struct List** head, int data) {
    if(*head == NULL) {
        *head = malloc(sizeof(struct List));
        (*head)->data = data;
        (*head)->prev = NULL;
        (*head)->next = NULL;
        return *head;

    } else {
        struct List* h = * head;
        while (h->next != NULL) {
            h = h->next;
        }
        h->next = malloc(sizeof(struct List));
        h->next->data = data;
        h->next->prev = h;
        h->next->next = NULL;
        return h->next;
    }
}

struct List* find(struct List *head, int data) {
    while (head != NULL) {
        if (head->data == data) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

void insert_list(struct List* head ) {

}

void removeList(struct List** head, struct List* node) {

}

size_t count(struct List *head) {
    size_t count = 0;
    while (head != NULL) {
        ++count;
        head = head->next;
    }
    return count;
}

void list_print(struct List *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
