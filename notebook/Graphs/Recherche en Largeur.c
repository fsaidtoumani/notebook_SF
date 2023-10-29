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

    BFS(&g, 3);

    return 0;
}
////////////////////////////////////////////////////////////////////

 
#define MAX 1000
 
typedef struct {
    int x, y;
    char dir;
} Node;
 
Node queue[MAX * MAX];
int front = 0, rear = 0;
 
char labyrinth[MAX][MAX];
Node prev[MAX][MAX];
bool visited[MAX][MAX];
int n, m;
 
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char directions[] = {'U', 'D', 'L', 'R'};
 
void bfs(int startX, int startY) {
    front = rear = 0;
    queue[rear++] = (Node){startX, startY, 0};
    visited[startX][startY] = true;
 
    while (front < rear) {
        Node current = queue[front++];
        for (int d = 0; d < 4; d++) {
            int nx = current.x + dx[d];
            int ny = current.y + dy[d];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && labyrinth[nx][ny] != '#') {
                visited[nx][ny] = true;
                prev[nx][ny] = current;
                prev[nx][ny].dir = directions[d];
                queue[rear++] = (Node){nx, ny, 0};
            }
        }
    }
}
 
void reconstruct_path(int startX, int startY, int endX, int endY) {
    char path[MAX * MAX];
    int length = 0;
 
    while (endX != startX || endY != startY) {
        path[length++] = prev[endX][endY].dir;
        Node temp = prev[endX][endY];
        endX = temp.x;
        endY = temp.y;
    }
 
    printf("YES\n%d\n", length);
    for (int i = length - 1; i >= 0; i--) {
        putchar(path[i]);
    }
    putchar('\n');
}
 
int main() {
    scanf("%d %d", &n, &m);
    int startX, startY, endX, endY;
 
    for (int i = 0; i < n; i++) {
        scanf("%s", labyrinth[i]);
        for (int j = 0; j < m; j++) {
            if (labyrinth[i][j] == 'A') {
                startX = i;
                startY = j;
            }
            if (labyrinth[i][j] == 'B') {
                endX = i;
                endY = j;
            }
        }
    }
 
    bfs(startX, startY);
 
    if (visited[endX][endY]) {
        reconstruct_path(startX, startY, endX, endY);
    } else {
        printf("NO\n");
    }
 
    return 0;
}