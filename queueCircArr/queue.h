#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef int T;

typedef struct s_queue{
    int frnt, rear, size;
    T qu[8192];
    unsigned capacity;
}               t_queue;

t_queue* createQueue(unsigned capacity);
bool isFull(t_queue* queue);
bool isEmpty(t_queue* queue);
void enqueue(t_queue* queue, const T value);
T dequeue(t_queue* queue);
T front(t_queue* queue);
T rear(t_queue* queue);
void printQu(t_queue* queue);

#endif