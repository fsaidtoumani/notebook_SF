#include <stdio.h>
#include <stdlib.h>

#define MAX_N 200000

// Structure to represent an edge
struct Edge {
    int to;
    struct Edge* next;
};

struct Edge* graph[MAX_N + 1];  // Adjacency list representation of the tree
int maxDepth = 0;

// Depth-First Search to find the diameter
int dfs(int node, int parent) {
    int maxDepth1 = 0, maxDepth2 = 0;
    struct Edge* edge = graph[node];

    while (edge != NULL) {
        int neighbor = edge->to;
        if (neighbor != parent) {
            int depth = dfs(neighbor, node);
            if (depth > maxDepth1) {
                maxDepth2 = maxDepth1;
                maxDepth1 = depth;
            } else if (depth > maxDepth2) {
                maxDepth2 = depth;
            }
        }
        edge = edge->next;
    }

    // Update the diameter
    maxDepth = (maxDepth > maxDepth1 + maxDepth2) ? maxDepth : maxDepth1 + maxDepth2;

    // Return the maximum depth rooted at this node
    return maxDepth1 + 1;
}

int main() {
    int n;
    scanf("%d", &n);

    // Initialize the graph
    for (int i = 1; i <= n; i++) {
        graph[i] = NULL;
    }

    // Build the tree
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        struct Edge* edge1 = (struct Edge*)malloc(sizeof(struct Edge));
        edge1->to = b;
        edge1->next = graph[a];
        graph[a] = edge1;

        struct Edge* edge2 = (struct Edge*)malloc(sizeof(struct Edge));
        edge2->to = a;
        edge2->next = graph[b];
        graph[b] = edge2;
    }

    dfs(1, 0);  // Start the DFS from node 1 as the root

    printf("%d\n", maxDepth);

    return 0;
}
