#include <stdio.h>
int a[10][10], visited[10], n;
void dfs(int u) {
	visited[u] = 1;
	printf("%d  ", u);
	for (int v = 0; v < n; v++)
		if (a[u][v] == 1 && visited[v] == 0)
			dfs(v);
}

void main() {
	int source;
	printf("Enter the number of vertices: ");
	scanf("%d", &n);
	printf("Enter graph as adjacency matrix:\n");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	for (int i = 0; i < n; i++)
		visited[i] = 0;
	printf("Enter source vertex: ");
	scanf("%d", &source);
	printf("DFS of given graph:\n");
	printf("Nodes visited from source node %d are: ", source);
	dfs(source);
	printf("\n");
}
