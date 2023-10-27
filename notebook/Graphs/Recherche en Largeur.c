#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct {
    int V; // Nombre de sommets
    int adj[MAX][MAX]; // Matrice d'adjacence
} Graph;

void initGraph(Graph *g, int V) {
    g->V = V;
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            g->adj[i][j] = 0;
        }
    }
}

void addEdge(Graph *g, int src, int dest) {
    g->adj[src][dest] = 1;
    g->adj[dest][src] = 1; // Si le graphe est non dirigé
}

void BFS(Graph *g, int start) {
    int visited[MAX] = {0};
    int queue[MAX], front = -1, rear = -1;

    void enqueue(int v) {
        if(rear == MAX-1) return;
        if(front == -1) front = 0;
        queue[++rear] = v;
    }

    int dequeue() {
        if(front == -1) return -1;
        int v = queue[front];
        if(front == rear) front = rear = -1;
        else front++;
        return v;
    }

    printf("%d ", start);
    visited[start] = 1;
    enqueue(start);
    while(front != -1) {
        int curr = dequeue();
        for(int i = 0; i < g->V; i++) {
            if(g->adj[curr][i] == 1 && !visited[i]) {
                printf("%d ", i);
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

int main() {
    Graph g;
    initGraph(&g, 6); // Création d'un graphe avec 5 sommets (0,1,2,3,4)

    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 5, 5);
    addEdge(&g, 3, 4);

    printf("BFS à partir du sommet 0: ");
    BFS(&g, 3);

    return 0;
}