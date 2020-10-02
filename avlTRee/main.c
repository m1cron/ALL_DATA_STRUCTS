#include <stdlib.h>

#include "avl.h"
    /*      30
           /  \
         20   40
        /  \     \
       10  25    50 */
int main(void) {
    t_node *root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    printPreOrder(root);

    return 0; 
} 