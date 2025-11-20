//Detecting whether graph is bi-connected or not

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int visited[MAX], disc[MAX], low[MAX], parent[MAX], timeCount = 0, foundArticulation = 0;

struct node {
    int vertex;
    struct node* next;
};

struct node* graph[MAX];

void addEdge(int u, int v) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->vertex = v;
    temp->next = graph[u];
    graph[u] = temp;

    temp = (struct node*)malloc(sizeof(struct node));
    temp->vertex = u;
    temp->next = graph[v];
    graph[v] = temp;
}

void dfs(int u) {
    visited[u] = 1;
    disc[u] = low[u] = ++timeCount;

    int child = 0;
    struct node* ptr = graph[u];

    while (ptr != NULL) {
        int v = ptr->vertex;

        if (!visited[v]) {
            parent[v] = u;
            child++;
            dfs(v);

            if (low[v] < low[u])
                low[u] = low[v];

            if (parent[u] != -1 && low[v] >= disc[u])
                foundArticulation = 1;

            if (parent[u] == -1 && child > 1)
                foundArticulation = 1;
        }
        else if (v != parent[u]) {
            if (disc[v] < low[u])
                low[u] = disc[v];
        }

        ptr = ptr->next;
    }
}

int main() {
    int n, e;
    int i;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        graph[i] = NULL;

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v):\n");
    for (i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    for (i = 0; i < n; i++) {
        visited[i] = 0;
        parent[i] = -1;
        disc[i] = 0;
        low[i] = 0;
    }

    dfs(0);

    // check if all visited (graph connected)
    int allVisited = 1;
    for (i = 0; i < n; i++) {
        if (!visited[i]) {
            allVisited = 0;
            break;
        }
    }

    if (!allVisited || foundArticulation == 1)
        printf("Graph is NOT BICONNECTED.\n");
    else
        printf("Graph IS BICONNECTED.\n");

    return 0;
}