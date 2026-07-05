/*
LAB TASK 11B
11 b. Implement a C program for BFS traversal on graph.
Note : Also visit the finally unvisited nodes.
       Do test for invalid start vertex.  
INPUT FORMAT: FIRST LINE NO OF VERTICES 'n', 
              IN NEXT 'n' LINES THE ADJACENCY MATRIX OF THE GRAPH.
              LAST LINE IS THE START VERTEX OF THE BFS TRAVERSAL.
OUTPUT FORMAT: DISPLAY THE BFS TARVERSAL AS PER THE GIVEN TEST CASE FORMAT.
               ALSO HANDLE NOT POSSIBLE SITUATIONS ACCORDINGLY.
               
Sample Test Cases:
case=t8
input=
4
0 1 0 1
1 0 1 1
0 1 0 1
0 1 1 0
3
output=
"THE BREADTH FIRST SEARCH TRAVERSAL OF THE GIVEN GRAPH IS :
 3 -> 2 -> 4 -> 1 ->"
*/
//Start writing program from here
#include <stdio.h>

int adj[100][100];
int visited[100];
int queue[10000];
int front, rear;
int n;

void enqueue(int val) {
    queue[rear++] = val;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

void bfs(int start) {
    visited[start] = 1;
    enqueue(start);

    while (!isEmpty()) {
        int node = dequeue();
        printf(" %d ->", node + 1);

        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
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

    // Validate start vertex
    if (start < 1 || start > n) {
        printf("Invalid Start Vertex - Cannot perform BFS.\n");
        return 0;
    }

    printf("THE BREADTH FIRST SEARCH TRAVERSAL OF THE GIVEN GRAPH IS :\n");

    front = rear = 0;
    start--; // convert to 0-indexed

    // BFS from start node
    bfs(start);

    // Visit remaining unvisited nodes (disconnected components)
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bfs(i);
        }
    }

    printf("\n");
    return 0;
}
