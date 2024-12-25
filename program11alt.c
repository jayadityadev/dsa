#include <stdio.h>
#include <stdlib.h>

int adjacencyMatrix[50][50], numVertices, visited[50];
int queue[20], front = -1, rear = -1;
int stack[20], top = -1;

void bfs(int startVertex) {
    int i, currentVertex;
    visited[startVertex] = 1;
    queue[++rear] = startVertex;
    while (front != rear) {
        currentVertex = queue[++front];
        for (i = 1; i <= numVertices; i++) {
            if ((adjacencyMatrix[currentVertex][i] == 1) && (visited[i] == 0)) {
                queue[++rear] = i;
                visited[i] = 1;
                printf("%d ", i);
            }
        }
    }
}

void dfs(int startVertex) {
    int i;
    visited[startVertex] = 1;
    stack[++top] = startVertex;
    for (i = 1; i <= numVertices; i++) {
        if (adjacencyMatrix[startVertex][i] == 1 && visited[i] == 0) {
            printf("%d ", i);
            dfs(i);
        }
    }
}

int main() {
    int choice, startVertex, i, j;
    printf("\nEnter the number of vertices in graph:  ");
    scanf("%d", &numVertices);
    printf("\nEnter the adjacency matrix:\n");
    for (i = 1; i <= numVertices; i++) {
        for (j = 1; j <= numVertices; j++) {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }

    printf("\nEnter the starting vertex: ");
    scanf("%d", &startVertex);

    printf("\n==>1. BFS: Print all nodes reachable from a given starting node");
    printf("\n==>2. DFS: Print all nodes reachable from a given starting node");
    printf("\n==>3: Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\nNodes reachable from starting vertex %d are: ", startVertex);
            for (i = 1; i <= numVertices; i++) {
                visited[i] = 0;
            }
            bfs(startVertex);
            break;

        case 2:
            printf("\nNodes reachable from starting vertex %d are:\n", startVertex);
            for (i = 1; i <= numVertices; i++) {
                visited[i] = 0;
            }
            dfs(startVertex);
            break;

        case 3:
            exit(0);

        default:
            printf("\nPlease enter a valid choice:");
    }

    return 0;
}
