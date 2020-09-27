#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "queue.h"

t_queue* createQueue(unsigned capacity){
    t_queue *ptr = (t_queue*)malloc(sizeof(t_queue));
    ptr->capacity = capacity;
    ptr->size = 0;
    ptr->frnt = 0;
    ptr->rear = capacity - 1;
    return ptr;
}

bool isFull(t_queue* queue){ return ((unsigned) queue->size == queue->capacity); }
bool isEmpty(t_queue* queue){ return (queue->size == 0); }

void enqueue(t_queue* queue, const T value){
    if(isFull(queue)) return;
    queue->qu[(queue->rear++ + 1) % queue->capacity] = value;
    queue->size++;
}

T dequeue(t_queue* queue){
    if(isEmpty(queue)) return -100;
    queue->size--;
    return queue->qu[(queue->frnt++) % queue->capacity];
}

T front(t_queue* queue){
    if(isEmpty(queue)) return -100;
    return queue->qu[queue->frnt];
}

T rear(t_queue* queue){
    if(isEmpty(queue)) return -100;
    return queue->qu[queue->rear];
}

void printQu(t_queue* queue){
    if(isEmpty(queue)) return;
    for(int i = queue->frnt; i <= queue->rear; i++)
        printf("| %d ", queue->qu[i]);
    printf("|");
}