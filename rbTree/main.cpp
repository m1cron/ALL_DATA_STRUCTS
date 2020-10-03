#include <bits/stdc++.h>

#include "RBTree.h"

int main(void) {
    printf("red = 0\t black = 1\n");

    t_node      *root = NULL;

    root = insertValue(root,10);
    root = insertValue(root, 20);
    root = insertValue(root, 30);
    root = insertValue(root, 40);
    root = insertValue(root, 50);
    root = insertValue(root, 25);
    preorderBST(root); root = deleteValue(root, 10); printf("|----------|\n"); preorderBST(root);
}