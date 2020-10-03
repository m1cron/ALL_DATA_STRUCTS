#include <bits/stdc++.h>

#include "RBTree.h"

t_node      *newNode(T data) {
    t_node *temp = (t_node*)malloc(sizeof(t_node));
    temp->data = data;
    temp->color = RED;
    temp->left = temp->right = temp->parent = NULL;
    return (temp);
}

int         getColor(t_node *node) {
    if (node == NULL)
        return (BLACK);
    return node->color;
}

void        setColor(t_node *node, int color) {
    if (node == NULL)
        return;
    node->color = color;
}

t_node      *insertBST(t_node *root, t_node *ptr) {
    if (root == NULL)
        return ptr;

    if (ptr->data < root->data) {
        root->left = insertBST(root->left, ptr);
        root->left->parent = root;
    } else if (ptr->data > root->data) {
        root->right = insertBST(root->right, ptr);
        root->right->parent = root;
    }
    return root;
}

t_node      *insertValue(t_node *root, T key) {
    t_node *node = newNode(key);
    root = insertBST(root, node);

    return fixInsertRBTree(root, node);
}

t_node      *rotateLeft(t_node *root, t_node *ptr) {
    t_node *right_child = ptr->right;
    ptr->right = right_child->left;

    if (ptr->right != NULL)
        ptr->right->parent = ptr;

    right_child->parent = ptr->parent;

    if (ptr->parent == NULL)
        root = right_child;
    else if (ptr == ptr->parent->left)
        ptr->parent->left = right_child;
    else
        ptr->parent->right = right_child;

    right_child->left = ptr;
    ptr->parent = right_child;
    return root;
}

t_node      *rotateRight(t_node *root, t_node *ptr) {
    t_node *left_child = ptr->left;
    ptr->left = left_child->right;

    if (ptr->left != NULL)
        ptr->left->parent = ptr;

    left_child->parent = ptr->parent;

    if (ptr->parent == NULL)
        root = left_child;
    else if (ptr == ptr->parent->left)
        ptr->parent->left = left_child;
    else
        ptr->parent->right = left_child;

    left_child->right = ptr;
    ptr->parent = left_child;
    return root;
}

t_node      *fixInsertRBTree(t_node *root, t_node *ptr) {
    t_node *parent = NULL;
    t_node *grandparent = NULL;
    while (ptr != root && getColor(ptr) == RED && getColor(ptr->parent) == RED) {
        parent = ptr->parent;
        grandparent = parent->parent;
        if (parent == grandparent->left) {
            t_node *uncle = grandparent->right;
            if (getColor(uncle) == RED) {
                setColor(uncle, BLACK);
                setColor(parent, BLACK);
                setColor(grandparent, RED);
                ptr = grandparent;
            } else {
                if (ptr == parent->right) {
                    root = rotateLeft(root, parent);
                    ptr = parent;
                    parent = ptr->parent;
                }
                root = rotateRight(root, grandparent);
                std::swap(parent->color, grandparent->color);
                ptr = parent;
            }
        } else {
            t_node *uncle = grandparent->left;
            if (getColor(uncle) == RED) {
                setColor(uncle, BLACK);
                setColor(parent, BLACK);
                setColor(grandparent, RED);
                ptr = grandparent;
            } else {
                if (ptr == parent->left) {
                    root = rotateRight(root, parent);
                    ptr = parent;
                    parent = ptr->parent;
                }
                root = rotateLeft(root, grandparent);
                std::swap(parent->color, grandparent->color);
                ptr = parent;
            }
        }
    }
    setColor(root, BLACK);
    return root;
}

t_node      *fixDeleteRBTree(t_node *root, t_node *node) {
    if (node == NULL)
        return NULL;

    if (node == root) {
        root = NULL;
        return root;
    }

    if (getColor(node) == RED || getColor(node->left) == RED || getColor(node->right) == RED) {
        t_node *child = node->left != NULL ? node->left : node->right;

        if (node == node->parent->left) {
            node->parent->left = child;
            if (child != NULL)
                child->parent = node->parent;
            setColor(child, BLACK);
            free(node);
        } else {
            node->parent->right = child;
            if (child != NULL)
                child->parent = node->parent;
            setColor(child, BLACK);
            delete (node);
        }
    } else {
        t_node *sibling = NULL;
        t_node *parent = NULL;
        t_node *ptr = node;
        setColor(ptr, DOUBLE_BLACK);
        while (ptr != root && getColor(ptr) == DOUBLE_BLACK) {
            parent = ptr->parent;
            if (ptr == parent->left) {
                sibling = parent->right;
                if (getColor(sibling) == RED) {
                    setColor(sibling, BLACK);
                    setColor(parent, RED);
                    root = rotateLeft(root, parent);
                } else {
                    if (getColor(sibling->left) == BLACK && getColor(sibling->right) == BLACK) {
                        setColor(sibling, RED);
                        if(getColor(parent) == RED)
                            setColor(parent, BLACK);
                        else
                            setColor(parent, DOUBLE_BLACK);
                        ptr = parent;
                    } else {
                        if (getColor(sibling->right) == BLACK) {
                            setColor(sibling->left, BLACK);
                            setColor(sibling, RED);
                            root = rotateRight(root, sibling);
                            sibling = parent->right;
                        }
                        setColor(sibling, parent->color);
                        setColor(parent, BLACK);
                        setColor(sibling->right, BLACK);
                        root = rotateLeft(root, parent);
                        break;
                    }
                }
            } else {
                sibling = parent->left;
                if (getColor(sibling) == RED) {
                    setColor(sibling, BLACK);
                    setColor(parent, RED);
                    root = rotateRight(root, parent);
                } else {
                    if (getColor(sibling->left) == BLACK && getColor(sibling->right) == BLACK) {
                        setColor(sibling, RED);
                        if (getColor(parent) == RED)
                            setColor(parent, BLACK);
                        else
                            setColor(parent, DOUBLE_BLACK);
                        ptr = parent;
                    } else {
                        if (getColor(sibling->left) == BLACK) {
                            setColor(sibling->right, BLACK);
                            setColor(sibling, RED);
                            root = rotateLeft(root, sibling);
                            sibling = parent->left;
                        }
                        setColor(sibling, parent->color);
                        setColor(parent, BLACK);
                        setColor(sibling->left, BLACK);
                        root = rotateRight(root, parent);
                        break;
                    }
                }
            }
        }
        if (node == node->parent->left)
            node->parent->left = NULL;
        else
            node->parent->right = NULL;
        delete(node);
        setColor(root, BLACK);
    }
    return root;
}

t_node      *deleteBST(t_node *root, T data) {
    if (root == NULL)
        return root;

    if (data < root->data)
        return deleteBST(root->left, data);

    if (data > root->data)
        return deleteBST(root->right, data);

    if (root->left == NULL || root->right == NULL)
        return root;

    t_node *temp = minValueNode(root->right);
    root->data = temp->data;
    return deleteBST(root->right, temp->data);
}

t_node      *deleteValue(t_node *root, T data) {
    t_node *node = deleteBST(root, data);
    return fixDeleteRBTree(root, node);
}

void        inorderBST(t_node *ptr) {
    if (ptr == NULL)
        return;
    inorderBST(ptr->left);
    printf("|%d\t %d |\n", ptr->data, ptr->color);
    inorderBST(ptr->right);
}

void        preorderBST(t_node *ptr) {
    if (ptr == NULL)
        return;
    printf("|%d\t %d |\n", ptr->data, ptr->color);
    preorderBST(ptr->left);
    preorderBST(ptr->right);
}

void        backtrackBST(t_node *ptr) {
    if (ptr == NULL)
        return;
    preorderBST(ptr->left);
    preorderBST(ptr->right);
    printf("|%d\t %d |\n", ptr->data, ptr->color);
}

t_node      *minValueNode(t_node *node) {
    t_node *ptr = node;
    while (ptr->left != NULL)
        ptr = ptr->left;
    return ptr;
}

t_node*     maxValueNode(t_node *node) {
    t_node *ptr = node;
    while (ptr->right != NULL)
        ptr = ptr->right;
    return ptr;
}

int         getBlackHeight(t_node *node) {
    int blackheight = 0;
    while (node != NULL) {
        if (getColor(node) == BLACK)
            blackheight++;
        node = node->left;
    }
    return blackheight;
}