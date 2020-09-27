#ifndef TREE_H
#define TREE_H

typedef int T;

typedef struct s_node
{
    T data;
    struct s_node *left, *right; 
}              t_node;

t_node         *newNode(T data);
t_node         *insert(t_node *root, T key);
void            directTraversal(t_node *root);      // NLR
void            centralTraversal(t_node *root);     // LNR
void            backtrackTraversal(t_node *root);   // LRN
unsigned        maxDepth(t_node *node);
unsigned        getLeafCount(t_node *node);
int             findLevel(t_node *root, T k, unsigned level);
T               addBT(t_node *root);
unsigned        btNodesCount(t_node *root);
t_node          *minValueNode(t_node *node);
t_node          *deleteNode(t_node *root, T key);
t_node          *freeNode(t_node *root);
t_node          *search(t_node *root, T key);

#endif