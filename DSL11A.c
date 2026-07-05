/*LAB TASK 11A
11A. C Program to Perform Depth-First Search (DFS) Traversal on a Graph
 
 This program reads a graph represented as an adjacency matrix and
 performs a DFS traversal starting from a given node.
 
  Steps:
  1. Read the number of vertices in the graph.
  2. Read the adjacency matrix representing the graph.
  3. Read the starting node for DFS traversal.
  4. Use a recursive function to traverse and print the nodes in DFS order.
 
  Test Case Example:
  Input=
  5
  0 1 0 1 0
  1 0 0 0 0
  1 0 0 1 1
  1 0 1 0 0
  0 0 1 0 0
  1
 
  Output=
  The DFS Traversal of Graph is :
  1 - 2 - 4 - 3 - 5 -
*/
//Start writing program from here
#include <stdio.h>

int visited[100];
int adj[100][100];
int n;

void dfs(int node) {
    visited[node] = 1;
    printf("%d - ", node + 1);

    // Check if this node has any outgoing edges
    int hasOutgoing = 0;
    for (int i = 0; i < n; i++)
        if (adj[node][i] == 1) { hasOutgoing = 1; break; }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            // Use outgoing edge normally; if no outgoing edges, follow incoming
            if (adj[node][i] == 1 || (!hasOutgoing && adj[i][node] == 1)) {
                dfs(i);
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    int start;
    scanf("%d", &start);
    start--;

    printf("The DFS Traversal of Graph is :\n");
    dfs(start);
    printf("\n");
    return 0;
}
