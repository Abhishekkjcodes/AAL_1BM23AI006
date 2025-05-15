#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX], visited[MAX], stack[MAX], top = -1;
int n;

void push(int vertex) {
    stack[++top] = vertex;
}

void dfs(int vertex) {
    visited[vertex] = 1;
    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] && !visited[i]) {
            dfs(i);
        }
    }
    push(vertex);
}

void topologicalSort() {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    printf("Topological Sort: ");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}

int main() {
    n = 6; // Number of vertices
    int edges[][2] = {
        {5, 2},
        {5, 0},
        {4, 0},
        {4, 1},
        {2, 3},
        {3, 1}
    };
    int edgeCount = sizeof(edges) / sizeof(edges[0]);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < edgeCount; i++) {
        graph[edges[i][0]][edges[i][1]] = 1;
    }

    topologicalSort();
    return 0;
}
