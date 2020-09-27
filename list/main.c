#include <stdio.h>

#include "list.h"

int main() {
    t_list *head = NULL;

    head = push_front(head, 1);
    head = push_front(head, 2);
    head = push_front(head, 3);
    push_back(head, 333);
    push_MEGDU(head->next->next, 1337);

    printList(head);
    printf("\t search: [%d] -> %d\n", 1337, search(head, 1337));

    head = pop_front(head);
    head = push_front(head, 4);
    pop_back(head);
    push_back(head, 228);

    printList(head);
    head = free_list(head);
    return 0;
}