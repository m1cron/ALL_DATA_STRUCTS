#include <stdlib.h>
#include <stdio.h>

#include "tree.h"

int main(void){/* 
              50 
           /     \ 
          30      70 
         /  \    /  \ 
       20   40  60   80 */

    t_node *root = NULL;
    root = insert(root, 50);
    insert(root, 30); insert(root, 20); insert(root, 40); insert(root, 70); insert(root, 60); insert(root, 80);

    directTraversal(root); printf("\n");
    centralTraversal(root); printf("\n");
    backtrackTraversal(root); printf("\n");
    //printf("Depth\t\t-->>\t%d\n", maxDepth(root));
    //printf("Depth by key\t-->>\t%d\n", findLevel(root, 50, 0));
    //printf("Sum all BT\t-->>\t%d\n", addBT(root));
    //printf("Leaf Count\t-->>\t%d\n", getLeafCount(root));
    //printf("Nodes Count\t-->>\t%d\n", btNodesCount(root));
    //printf("Average all BT\t-->>\t%d\n", (int)(addBT(root) / btNodesCount(root)));
    root = deleteNode(root, 30); directTraversal(root); printf("\n");
    t_node *temp = search(root, 20); printf("Search result \t-->>\t%d\n", temp->data);
    
    root = freeNode(root);
    return (0);
}