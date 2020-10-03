#ifndef RB_TREE_H
#define RB_TREE_H

typedef int T;

enum Color { RED, BLACK, DOUBLE_BLACK };

typedef struct      s_node {
    T               data;
    int             color;
    struct s_node   *left, *right, *parent;
}                   t_node;

t_node              *newNode(T data);
int                 getColor(t_node *node);
void                setColor(t_node *node, int color);
t_node*             insertBST(t_node *root, t_node *ptr);
t_node              *insertValue(t_node *root, T key);

t_node              *rotateLeft(t_node *root, t_node *ptr);
t_node              *rotateRight(t_node *root, t_node *ptr);
t_node              *fixInsertRBTree(t_node *root, t_node *ptr);
t_node              *fixDeleteRBTree(t_node *root, t_node *node);
t_node              *deleteBST(t_node *root, T data);
t_node              *deleteValue(t_node *root, T data);

void                inorderBST(t_node *ptr);
void                preorderBST(t_node *ptr);
void                backtrackBST(t_node *ptr);

t_node              *minValueNode(t_node *node);
t_node              *maxValueNode(t_node *node);
int                 getBlackHeight(t_node *node);

#endif