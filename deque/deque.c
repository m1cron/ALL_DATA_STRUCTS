#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
 *      REAR      FRONT
 */

deque *createDeq(int capacity){
    deque *ptr = (deque*)malloc(sizeof(deque));
    assert(ptr != NULL);

    ptr->deq = (T*)malloc(sizeof(T) * capacity);
    assert(ptr->deq != NULL);

    ptr->front = -1;
    ptr->rear = 0;
    ptr->size = capacity;
    return ptr;
}

_Bool isEmpty(struct deque *ptr){ return (ptr->front == -1); }

_Bool isFull(struct deque *ptr){
    return ((ptr->front == ptr->rear + 1) || (ptr->front == 0 && ptr->rear == ptr->size - 1));
}

void resize(struct deque *ptr){
    ptr->deq = realloc(ptr->deq, sizeof(T) * ptr->size * 2);
}

void insetFront(struct deque *ptr, T value){
    if(isFull(ptr)){
        printf("Overflow!\n");
        return;
    }
    if(ptr->front == -1)
        ptr->front = ptr->rear = 0;
    else if(ptr->front == 0)
        ptr->front = ptr->size - 1;
    else
        ptr->front--;
    ptr->deq[ptr->front] = value;
}

void insertRear(struct deque *ptr, T value){
    if(isFull(ptr)){
        printf("Overflow!\n");
        return;
    }
    if(ptr->front == -1)
        ptr->front = ptr->rear = 0;
    else if(ptr->rear == ptr->size - 1)
        ptr->rear = 0;
    else
        ptr->rear++;
    ptr->deq[ptr->rear] = value;
}

void deleteFront(struct deque *ptr){
    if(isEmpty(ptr)){
        printf("Deque UnderFlow!\n");
        return;
    }
    if(ptr->front == ptr->rear)
        ptr->front = ptr->rear = -1;
    else
        if(ptr->front == ptr->size - 1)
            ptr->front = 0;
        else
            ptr->front++;
}

void deleteRear(struct deque *ptr){
    if(isEmpty(ptr)){
        printf("Deque UnderFlow!\n");
        return;
    }
    if(ptr->front == ptr->rear)
        ptr->front = ptr->rear = -1;
    else if(ptr->rear == 0)
        ptr->rear = ptr->size - 1;
    else
        ptr->rear--;
}

T getFront(struct deque *ptr){
    if(isEmpty(ptr)){
        printf("UnderFlow!\n");
        return -1;
    }
    return ptr->deq[ptr->front];
}

T getRear(struct deque *ptr){
    if(isEmpty(ptr) || ptr->rear < 0){
        printf("UnderFlow!\n");
        return -1;
    }
    return ptr->deq[ptr->rear];
}

void printDeq(struct deque *ptr){
    while (!isEmpty(ptr)) {
        printf("| %d ", getFront(ptr));
        deleteFront(ptr);
    }
    printf("|");
}