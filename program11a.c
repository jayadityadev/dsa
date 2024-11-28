#include <stdio.h>
#include <stdlib.h>

void bfs(int a[10][10], int n, int u) {
	int front, rear, q[10], visited[10];
	for (int i = 0; i < n; i++) visited[i] = 0;
	front = 0; rear = -1;
	printf("\nThe nodes visited from %d are:\n", u);
	q[++rear] = u;
	visited[u] = 1;
	printf("%d  ", u);
	while (front <= rear) {
		u = q[front++];
		for (int v = 0; v < n; v++) {
			if (a[u][v] == 1 && visited[v] == 0) {
				printf("%d  ", v);
				visited[v] = 1;
				q[++rear] = v;
			}
		}
	}
}

void main() {
	int a[10][10], n, source;
	printf("Enter the number of vertices: ");
	scanf("%d", &n);
	printf("Enter the graph as adjacency matrix:\n");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	printf("Enter source vertex: ");
	scanf("%d", &source);
	printf("\nBFS of given graph: ");
	bfs(a, n, source);
	printf("\n");
}
