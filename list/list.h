#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

typedef int T;

typedef struct list{
    T data;
    struct list* next;
}               list;

void        printList(struct list* n);
bool        search(struct list* head, T data);
list        *push_front(struct list *ptr, T data);
void        push_back(struct list *head, T data);
void        push_MEGDU(struct list *head, T data);
list        *free_list(struct list* head);
list        *pop_front(struct list* head);
void        pop_back(struct list* head);

#endif