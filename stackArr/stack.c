#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

void push(stack *stack, const T value){
    if(stack->size >= STACK_SIZE) printf("throw stack overflow");
    else {
        stack->data[stack->size] = value;
        stack->size++;
    }
}

T pop(stack *stack){
    if(stack->size <= 0) exit(-102);
    else {
        stack->size--;
        return stack->data[stack->size];
    }
}

T peek(stack *stack){
    if(stack->size <= 0) exit(-10);
    else return stack->data[stack->size - 1];
}

void printEl(const T value){
    printf("%d", value);
}

void printStack(const stack* stack, void (*printEl)(const T)){
    for(int i = 0; i < stack->size; i++){
        printEl(stack->data[i]);
        printf(" | ");
    }
}