#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef int T;

typedef struct queue{
    int frnt, rear, size;
    T qu[8192];
    unsigned capacity;
} queue;

queue* createQueue(unsigned capacity);
bool isFull(queue* queue);
bool isEmpty(queue* queue);
void enqueue(queue* queue, const T value);
T dequeue(queue* queue);
T front(queue* queue);
T rear(queue* queue);
void printQu(queue* queue);

#endif