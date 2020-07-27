#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <assert.h>

typedef struct b_node{
    int n;
    struct node *left, *right;
}b_node;

bool b_search(int n, b_node* tree){
    if(tree == NULL) return false;
    else if (n < tree->n) return b_search(n, tree->left);
    else if (n > tree->n) return b_search(n, tree->right);
    else true;
}


typedef int T;

typedef struct list{
    T data;
    struct list* next;
} list;

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


int main() {
    struct list *head = NULL;

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
    //head = free_list(head);
    return 0;
}