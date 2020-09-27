#include <stdio.h>

#include "queue.h"

int main(void) {
    t_queue *queue = createQueue(4);
    for(int i = 0; i < 4; i++)
        enqueue(queue, i);
    enqueue(queue, 999);
    while (!isEmpty(queue))
        printf("| %d ", dequeue(queue));
    printf("|");
    return 0;
}