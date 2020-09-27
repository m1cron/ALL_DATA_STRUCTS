#ifndef DEQUE_H
#define DEQUE_H

/*
 *      REAR      FRONT
 */

typedef int T;


typedef struct deque{
    T *deq;
    int front, rear, size;
}               deque;

T getFront(struct deque *ptr);
T getRear(struct deque *ptr);
_Bool isEmpty(struct deque *ptr);
_Bool isFull(struct deque *ptr);

deque *createDeq(int capacity);
_Bool isEmpty(struct deque *ptr);
_Bool isFull(struct deque *ptr);
void resize(struct deque *ptr);
void insetFront(struct deque *ptr, T value);
void insertRear(struct deque *ptr, T value);
void deleteFront(struct deque *ptr);
void deleteRear(struct deque *ptr);
T getFront(struct deque *ptr);
T getRear(struct deque *ptr);
void printDeq(struct deque *ptr);


#endif