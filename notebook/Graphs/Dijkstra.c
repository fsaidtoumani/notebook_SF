#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define INF 1e9

typedef struct {
    int V; // Nombre de sommets
    int adj[MAX][MAX]; // Matrice d'adjacence (pour les poids)
} Graph;

void initGraph(Graph *g, int V) {
    g->V = V;
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            g->adj[i][j] = 0; // ou INF si on préfère indiquer qu'il n'y a pas de lien
        }
    }
}

void addEdge(Graph *g, int src, int dest, int weight) {
    g->adj[src][dest] = weight;
    // g->adj[dest][src] = weight; // Si le graphe est non dirigé
}

void dijkstra(Graph *g, int src) {
    int dist[MAX];
    int visited[MAX] = {0};

    for(int i = 0; i < g->V; i++) {
        dist[i] = INF;
    }
    dist[src] = 0;

    for(int i = 0; i < g->V - 1; i++) {
        int u = -1;

        // Trouver le sommet avec la distance minimale, parmi les sommets non traités.
        for(int j = 0; j < g->V; j++) {
            if(!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        visited[u] = 1;
        //
        for(int v = 0; v < g->V; v++) {
            if(!visited[v] && g->adj[u][v] && dist[u] + g->adj[u][v] < dist[v]) {
                dist[v] = dist[u] + g->adj[u][v];
            }
        }
    }

    // Affichage des distances
    for(int i = 0; i < g->V; i++) {
        printf("Distance du sommet %d au sommet %d = %d\n", src, i, dist[i]);
    }
}
int main() {
    Graph g;
    initGraph(&g, 6); // Création d'un graphe avec 5 sommets (0,1,2,3,4)

    addEdge(&g, 0, 1, 5);
    addEdge(&g, 0, 2, 3);
    addEdge(&g, 1, 3, 6);
    addEdge(&g, 1, 2, 2);
    addEdge(&g, 2, 4, 4);
    addEdge(&g, 2, 5, 2);
    addEdge(&g, 2, 3, 7);
    addEdge(&g, 3, 4, -1);
    addEdge(&g, 4, 5, -2);

    dijkstra(&g, 0);
    return 0;
}