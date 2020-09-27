#include <stdlib.h>
#include <stdio.h>

#include "tree.h"

t_node *newNode(T data){
    t_node *node = (t_node*)malloc(sizeof(t_node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

t_node *insert(t_node *node, T key){
    if (node == NULL)
        return (newNode(key));
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key >= node->data)
        node->right = insert(node->right, key);
    return (node);
}

void directTraversal(t_node *root){
    if (root != NULL) {
        printf("%d \t", root->data);
        directTraversal(root->left);
        directTraversal(root->right);
    }
}

void centralTraversal(t_node *root){
    if (root != NULL) {
        directTraversal(root->left);
        printf("%d \t", root->data);
        directTraversal(root->right);
    }
}

void backtrackTraversal(t_node *root){
    if (root != NULL) {
        directTraversal(root->left);
        directTraversal(root->right);
        printf("%d \t", root->data);
    }
}

unsigned maxDepth(t_node *node){
    if (node == NULL)
        return (0);
    else {
        unsigned l = maxDepth(node->left);
        unsigned r = maxDepth(node->right);

        if (l > r)
            return (l + 1);
        else
            return (r + 1);
    }
}

unsigned getLeafCount(t_node *node){
    if (node == NULL)
        return (0);
    if (node->left == NULL && node->right == NULL)
        return (1);
    else
        return (getLeafCount(node->left) + getLeafCount(node->right));
}

int findLevel(t_node *root, T k, unsigned level) {
    if (root == NULL) 
        return -1;
    if (root->data == k) 
        return level; 
  
    int l = findLevel(root->left, k, level+1); 
    return (l != -1)? l : findLevel(root->right, k, level+1); 
}

T addBT(t_node *root){
    if (root == NULL)
        return (0);
    return (root->data + addBT(root->left) + addBT(root->right));
}

unsigned btNodesCount(t_node *root) {
    if (root == NULL)
        return (0);
    unsigned count = 1;
    if (root->left != NULL)
       count += btNodesCount(root->left);
    if (root->right != NULL)
        count += btNodesCount(root->right);
    return (count);
}

t_node *minValueNode(t_node *node) {
    t_node *current = node;
    while (current && current->left != NULL)
        current = current->left;
    return (current);
}

t_node *deleteNode(t_node *root, T key){
    if (root == NULL)
        return (root);
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            t_node *temp = root->right;
            free(root);
            return (temp);
        }
        else if (root->right == NULL) {
            t_node *temp = root->left;
            free(root);
            return (temp);
        }
        t_node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return (root);
}

t_node *freeNode(t_node *root) {
    if (root == NULL)
        return (NULL);
    freeNode(root->left);
    //free(root->data);      // if u use *void insted of T data
    freeNode(root->right);
    free(root);
    return (NULL);
}

t_node *search(t_node *root, T key) {
    if (root == NULL || root->data == key)
        return (root);
    if (root->data < key)
        return (search(root->right, key));
    return (search(root->left, key));
}