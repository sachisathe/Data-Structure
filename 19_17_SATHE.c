//Printing BFS and DFS on graph

#include <stdio.h>
#define MAX 20

void DFS(int adj[MAX][MAX], int n, int start)
{
    int stack[MAX], top = -1;
    int visited[MAX] = {0};
    int i, val;

    
    stack[++top] = start;
    visited[start] = 1;

    printf("\nDFS Traversal: ");

    while (top != -1)
    {
        val = stack[top--];
        printf("%d ", val);

        for (i = n - 1; i >= 0; i--)
        {
            if (adj[val][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                stack[++top] = i;
            }
        }
    }
}

void BFS(int adj[MAX][MAX], int n, int start)
{
    int queue[MAX];
    int visited[MAX] = {0};
    int f = 0, r = -1;
    int i, val;

    visited[start] = 1;
    queue[++r] = start;

    printf("\nBFS Traversal: ");

    while (f <= r)
    {
        val = queue[f++];
        printf("%d ", val);

        for (i = 0; i < n; i++)
        {
            if (adj[val][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[++r] = i;
            }
        }
    }
}

int main()
{
    int adj[MAX][MAX], n;
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("Is there an edge between %d-%d? ", i, j);
            scanf("%d", &adj[i][j]);
        }
    }

    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter starting node for traversal: ");
    scanf("%d", &start);

    DFS(adj, n, start);
    BFS(adj, n, start);

    printf("\n");
    return 0;
}