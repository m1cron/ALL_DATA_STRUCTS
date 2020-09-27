#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"

void printList(struct list* n){
    while (n != NULL) {
        printf(" %d ", n->data);
        n = n->next;
    }
}

bool search(struct list* head, T data){
    struct list* temp = head;
    while(temp != NULL){
        if(temp->data == data) return true;
        else temp = temp->next;
    }
    return false;
}

list *push_front(struct list *ptr, T data){
    struct list* temp = (struct list*)malloc(sizeof(struct list));
    assert(temp != NULL); // memory error
    temp->data = data;
    temp->next = ptr;
    ptr = temp;
    return ptr;
}

void push_back(struct list *head, T data){
    struct list *current = head;
    while (current->next != NULL)
        current = current->next;

    current->next = (struct list*)malloc(sizeof(struct list));
    assert(current->next != NULL); // memory error

    current->next->data = data;
    current->next->next = NULL;
}

void push_MEGDU(struct list *head, T data){
    struct list* temp = (struct list*)malloc(sizeof(struct list));
    assert(temp != NULL); // memory error
    temp->data = data;
    /*  switching block  */
    temp->next = head->next;
    head->next = temp;
}

list *free_list(struct list* head){
    struct list* temp = head;
    struct list* followPtr;
    while(temp != NULL){
        followPtr = temp;
        temp = temp->next;
        free(followPtr);
    }
    return NULL;
}

list *pop_front(struct list* head){
    struct list *temp = head->next;
    free(head);
    return temp;
}

void pop_back(struct list* head){
    struct list *temp = head;
    while (temp != NULL){
        temp = temp->next;
    }
    free(temp);
}