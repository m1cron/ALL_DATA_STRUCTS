#include <stdio.h>

#include "stack.h"

int main(void) {
    stack stack;
    stack.size = 0;
    for(int i = 0; i <= 10; i++)
        push(&stack, i);
    printStack(&stack, printEl);
    return 0;
}