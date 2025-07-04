#include <stdio.h>
#define INF 99999

void floydWarshall(int graph[][100], int V) {
  int dist[100][100], i, j, k;
  for (i = 0; i < V; i++)
    for (j = 0; j < V; j++)
      dist[i][j] = graph[i][j];
  for (k = 0; k < V; k++) {
    for (i = 0; i < V; i++) {
      for (j = 0; j < V; j++) {
        if (dist[i][k] + dist[k][j] < dist[i][j])
          dist[i][j] = dist[i][k] + dist[k][j];
      }
    }
  }
  for (i = 0; i < V; i++) {
    for (j = 0; j < V; j++) {
      if (dist[i][j] == INF)
        printf("INF ");
      else
        printf("%d ", dist[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int graph[100][100] = {{0, 5, INF, 10},
                         {INF, 0, 3, INF},
                         {INF, INF, 0, 1},
                         {INF, INF, INF, 0}};
  int V = 4;
  floydWarshall(graph, V);
  return 0;
}
