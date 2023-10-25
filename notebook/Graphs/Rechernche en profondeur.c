#include <stdbool.h>
#include <stdio.h>

#define MAX_NODES 1000

bool visited[MAX_NODES];
int graph[MAX_NODES][MAX_NODES];

void dfs(int node, int n) {
    visited[node] = true;
    printf("Visited node: %d\n", node);

    for (int i = 0; i < n; i++) {
        if (graph[node][i] && !visited[i]) {
            dfs(i, n);
        }
    }
}
//Exemple implementation

#include <stdbool.h>
#include <stdio.h>

#define MAX_SIZE 1000

char map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
int n, m;

void dfs(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) return; // Vérifie les limites
    if (map[x][y] == '#' || visited[x][y]) return; // Vérifie les murs et les zones visitées

    visited[x][y] = true;

    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &map[i][j]);
            visited[i][j] = false;
        }
    }

    int rooms = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && map[i][j] == '.') {
                dfs(i, j);
                rooms++;
            }
        }
    }

    printf("%d\n", rooms);

    return 0;
}
