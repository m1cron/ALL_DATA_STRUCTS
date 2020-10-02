#ifndef RB_TREE_H
#define RB_TREE_H

typedef int T;

enum Color { RED, BLACK }

typedef struct s_node
{
    T data;
    bool color;
    struct s_node *left, *right, *parent; 
}              t_node;



#endif