#include "deque.h"

/*
 *      REAR      FRONT
 */

int main(void) {
    deque *deq = createDeq(3);

    insetFront(deq, 1);
    insetFront(deq, 2);
    insetFront(deq, 3);

    printDeq(deq);
    return 0;
}