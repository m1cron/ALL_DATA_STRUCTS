#include <limits.h>
#include<iostream>
#include<iomanip>
#include <stdio.h>
using namespace std;
 
int minKey(int key[], bool mstSet[], int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void printMST(int parent[], int **graph, int V) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}
 
void primMST(int **graph, int V) {
    int parent[V];
    int key[V];
    bool mstSet[V];
 
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;
 
    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);
 
        mstSet[u] = true;
 
        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
    printMST(parent, graph, V);
}

void PrintMatrix(int **matrix, int n) {
   int i, j;
      cout << "\n\n" << setw(4) << "";
   for(i = 0; i < n; i++)
      cout << setw(3) << "(" << i+1 << ")";
      cout << "\n\n";
   for(i = 0; i < n; i++) {
      cout << setw(3) << "(" << i+1 << ")";
      for(j = 0; j < n; j++) {
         cout << setw(4) << matrix[i][j];
      }
      cout << "\n\n";
   }
}

int main() {
    int V, v1, v2, len;
    cout << "(size) Enter the number of vertexes of the graph: ";
    cin >> V;

    int **graph = new int *[V];
    for (int i = 0; i < V; i++) {
        graph[i] = new int[V];
        for (int j = 0; j < V; j++)
            graph[i][j] = 0;
    }

    for (int i = 0; !cin.eof(); i++) {
        cout << "\nEnter the vertex pair for edge " << i + 1;
        cout << "\nFrom: ";
        cin >> v1;
        cout << "To: ";
        cin >> v2;
        cout << "Length: ";
        cin >> len;
        graph[v1 - 1][v2 - 1] = len;
        graph[v2 - 1][v1 - 1] = len;
    }

    PrintMatrix(graph, V);

    /*
     2 3
 (0)--(1)--(2)
 | / \ |
 6| 8/ \5 |7
 | /     \ |
 (3)-------(4)
         9             a  b  c  d  e
    graph[V][V] =  { { 0, 2, 0, 6, 0 },  // a
                     { 2, 0, 3, 8, 5 },  // b
                     { 0, 3, 0, 0, 7 },  // c
                     { 6, 8, 0, 0, 9 },  // d
                     { 0, 5, 7, 9, 0 } };// e */
    primMST(graph, V);
}