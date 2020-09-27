#ifndef STACK_H
#define STACK_H

#define INIT_SIZE 4;
#define MULTIPLIER 2;

typedef int T;

typedef struct stack{
    T *data;
    size_t size;
    size_t top;
}             stack;

stack*      createStack();
void        deleteStack(stack **stack);
void        resize(stack *stack);
void        push(stack *stack, const T value);
T           pop(stack* stack);
T           peek(const stack* stack);

#endif