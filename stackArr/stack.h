#include STACK_H
#define STACK_H

#define STACK_SIZE 20
typedef int T;

typedef struct stack{
    T data[STACK_SIZE];
    size_t size;
}               stack;

void        push(stack *stack, const T value);
T           pop(stack *stack);
T           peek(stack *stack);
void        printEl(const T value);
void        printStack(const stack* stack, void (*printEl)(const T));

#endif