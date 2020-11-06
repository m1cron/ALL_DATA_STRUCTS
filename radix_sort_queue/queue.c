#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "queue.h"

queue* createQueue(unsigned capacity){
    queue *ptr = (queue*)malloc(sizeof(queue));
    ptr->capacity = capacity;
    ptr->size = 0;
    ptr->frnt = 0;
    ptr->rear = capacity - 1;
    return ptr;
}

bool isFull(queue* queue){ return ((unsigned) queue->size == queue->capacity); }
bool isEmpty(queue* queue){ return (queue->size == 0); }

void enqueue(queue* queue, const T value){
    if(isFull(queue)) return;
    queue->qu[(queue->rear++ + 1) % queue->capacity] = value;
    queue->size++;
}

T dequeue(queue* queue){
    if(isEmpty(queue)) return -100;
    queue->size--;
    return queue->qu[(queue->frnt++) % queue->capacity];
}

T front(queue* queue){
    if(isEmpty(queue)) return -100;
    return queue->qu[queue->frnt];
}

T rear(queue* queue){
    if(isEmpty(queue)) return -100;
    return queue->qu[queue->rear];
}

void printQu(queue* queue){
    if(isEmpty(queue)) return;
    for(int i = queue->frnt; i <= queue->rear; i++)
        printf("| %d ", queue->qu[i]);
    printf("|");
}