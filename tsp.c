#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
int n;
int** graph;
int* path;
bool* visited;
int minCost = INT_MAX;

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int calculateCost() {
  int cost = 0;
  for (int i = 0; i < n - 1; i++) {
    cost += graph[path[i]][path[i + 1]];
  }
  cost += graph[path[n - 1]][path[0]];
  return cost;
}

void permute(int l, int r) {
  if (l == r) {
    int currentCost = calculateCost();
    if (currentCost < minCost) {
      minCost = currentCost;
    }
  } else {
    for (int i = l; i <= r; i++) {
      swap(&path[l], &path[i]);
      permute(l + 1, r);
      swap(&path[l], &path[i]);
    }
  }
}

int main() {
  printf("Enter the number of cities: ");
  scanf("%d", &n);

  graph = (int**)malloc(n * sizeof(int*));
  for (int i = 0; i < n; i++) {
    graph[i] = (int*)malloc(n * sizeof(int));
    printf("Enter the distances from city %d to all other cities:\n", i + 1);
    for (int j = 0; j < n; j++) {
      scanf("%d", &graph[i][j]);
    }
  }

  path = (int*)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    path[i] = i;
  }

  permute(1, n - 1);

  printf("Minimum cost: %d\n", minCost);

  for (int i = 0; i < n; i++) {
    free(graph[i]);
  }
  free(graph);
  free(path);

  return 0;
}