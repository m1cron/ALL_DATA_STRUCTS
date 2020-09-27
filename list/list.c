#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

#include "list.h"

void printList(t_list* n) {
    while (n != NULL) {
        printf(" %d ", n->data);
        n = n->next;
    }
    printf("\n");
}

bool search(t_list* head, T data){
    t_list* temp = head;
    while(temp != NULL){
        if(temp->data == data) return true;
        else temp = temp->next;
    }
    return false;
}

t_list *push_front(t_list *ptr, T data){
    t_list* temp = (t_list*)malloc(sizeof(t_list));
    assert(temp != NULL); // memory error
    temp->data = data;
    temp->next = ptr;
    ptr = temp;
    return ptr;
}

void push_back(t_list *head, T data){
    t_list *current = head;
    while (current->next != NULL)
        current = current->next;

    current->next = (t_list*)malloc(sizeof(t_list));
    assert(current->next != NULL); // memory error

    current->next->data = data;
    current->next->next = NULL;
}

void push_MEGDU(t_list *head, T data){
    t_list* temp = (t_list*)malloc(sizeof(t_list));
    assert(temp != NULL); // memory error
    temp->data = data;
    /*  switching block  */
    temp->next = head->next;
    head->next = temp;
}

t_list *free_list(t_list* head){
    t_list* temp = head;
    t_list* followPtr;
    while(temp != NULL){
        followPtr = temp;
        temp = temp->next;
        free(followPtr);
    }
    return NULL;
}

t_list *pop_front(t_list* head){
    t_list *temp = head->next;
    free(head);
    return temp;
}

void pop_back(t_list* head){
    t_list *temp = head;
    while (temp != NULL)
        temp = temp->next;
    free(temp);
}