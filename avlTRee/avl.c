#include <stdlib.h>
#include <stdio.h>

#include "avl.h"

int             height(t_node *node) {
    return ((node == NULL) ? 0 : node->height);
}

int             max(int a, int b) {
    return ((a > b) ? a : b);
}

void            printPreOrder(t_node *root) {
    if(root != NULL) {
        printf("%d ", root->data);
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

t_node          *newNode(T key) {
    t_node *node = (t_node*)malloc(sizeof(t_node));
    node->data = key;
    node->height = 1;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

int             getBalance(t_node *node) {
    return (node == NULL ? 0 : height(node->left) - height(node->right));
}

t_node          *rightRotate(t_node *y) {
    t_node *x = y->left;
    t_node *temp = x->right;

    x->right = y;
    y->left = temp;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return (x);
}

t_node          *leftRotate(t_node *x) {
    t_node *y = x->right;
    t_node *temp = y->left;

    y->left = x;
    x->right = temp;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return (y);
}

t_node          *insert(t_node *node, T key) {
    if (node == NULL)
        return (newNode(key));

    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    else
        return (node);
    
    node->height = 1 + max(height(node->left),
                           height(node->right));
    int balance = getBalance(node);

    if (balance > 1 && key < node->left->data)       // LL
        return (rightRotate(node));

    if (balance < -1 && key > node->right->data)     // RR
        return (leftRotate(node));

    if (balance > 1 && key > node->left->data) {     // LR
        node->left = leftRotate(node->left);
        return (rightRotate(node));
    }

    if (balance < -1 && key < node->right->data) {   // RL
        node->right = rightRotate(node->right);
        return (leftRotate(node));
    }

    return (node);
}
