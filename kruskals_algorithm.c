#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int u, v, weight;
} Edge;

Edge edges[MAX];
int parent[MAX];
int rank[MAX];
int edgeCount = 0;

int find(int i) {
    if (parent[i] == -1) {
        return i;
    }
    return find(parent[i]);
}

void unionSets(int u, int v) {
    int uRoot = find(u);
    int vRoot = find(v);
    if (uRoot != vRoot) {
        if (rank[uRoot] > rank[vRoot]) {
            parent[vRoot] = uRoot;
        } else if (rank[uRoot] < rank[vRoot]) {
            parent[uRoot] = vRoot;
        } else {
            parent[vRoot] = uRoot;
            rank[uRoot]++;
        }
    }
}

int compare(const void *a, const void *b) {
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

void kruskalMST(int n) {
    qsort(edges, edgeCount, sizeof(edges[0]), compare);
    for (int i = 0; i < n; i++) {
        parent[i] = -1;
        rank[i] = 0;
    }
    int mstWeight = 0;
    printf("Edges in the Minimum Spanning Tree:\n");
    for (int i = 0; i < edgeCount; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        if (find(u) != find(v)) {
            unionSets(u, v);
            printf("%d - %d, Weight: %d\n", u, v, edges[i].weight);
            mstWeight += edges[i].weight;
        }
    }
    printf("Total weight of MST: %d\n", mstWeight);
}

int main() {
    int n = 4; // Number of vertices
    edgeCount = 5; // Number of edges
    edges[0] = (Edge){0, 1, 10};
    edges[1] = (Edge){0, 2, 6};
    edges[2] = (Edge){0, 3, 5};
    edges[3] = (Edge){1, 3, 15};
    edges[4] = (Edge){2, 3, 4};
    kruskalMST(n);
    return 0;
}
