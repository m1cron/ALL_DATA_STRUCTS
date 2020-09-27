#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

typedef int T;

typedef struct s_list{
    T data;
    struct s_list* next;
}              t_list;

void            printList(t_list* n);
bool            search(t_list* head, T data);
t_list          *push_front(t_list *ptr, T data);
void            push_back(t_list *head, T data);
void            push_MEGDU(t_list *head, T data);
t_list          *free_list(t_list* head);
t_list          *pop_front(t_list* head);
void            pop_back(t_list* head);

#endif