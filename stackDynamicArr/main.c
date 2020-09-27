#include <stdio.h>

#include "stack.h"

int main(void) {
    stack *stack = createStack();
    for (int i = 0; i < 16; i++)
        push(stack, i);
    for (int i = 0; i < 16; i++) {
        printf("%d ", peek(stack));
        printf("%d ", pop(stack));
    }
    printf("\n");
    deleteStack(&stack);
    return 0;
}
