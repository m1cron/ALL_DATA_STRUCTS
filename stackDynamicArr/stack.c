#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

stack* createStack(){
    stack *ptr = (stack*)malloc(sizeof(stack));
    if (ptr == NULL) exit(-1);
    ptr->size = INIT_SIZE;
    ptr->data = (T*)malloc(sizeof(T) * ptr->size);
    if(ptr->data == NULL) exit(-1);
    ptr->top = 0;
    return ptr;
}

void deleteStack(stack **stack){
    free((*stack)->data);
    free(*stack);
};

void resize(stack *stack){
    stack->size *= MULTIPLIER;
    stack->data = (T*)realloc(stack->data, stack->size * sizeof(T));
    if(stack->data == NULL) exit(-1);
}

void push(stack *stack, const T value){
    if(stack->top >= stack->size) resize(stack);
    stack->data[stack->top] = value;
    stack->top++;
}

T pop(stack* stack){
    if(stack->top == 0) exit(-1);
    stack->top--;
    return stack->data[stack->top];
}

T peek(const stack* stack){
    if(stack->top <= 0) exit(-1);
    return stack->data[stack->top - 1];
}