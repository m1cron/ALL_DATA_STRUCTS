#ifndef AVL_H
#define AVL_H

typedef int T;

typedef struct  s_node
{
    T data;
    struct s_node *left, *right;
    int height;
}               t_node;

int             height(t_node *node);
int             max(int a, int b);
void            printPreOrder(t_node *root);
int             getBalance(t_node *node);

t_node          *newNode(T key);
t_node          *rightRotate(t_node *y);
t_node          *leftRotate(t_node *x);
t_node          *insert(t_node *node, T key);

#endif