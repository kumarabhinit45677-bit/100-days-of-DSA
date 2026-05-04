#include <stdio.h>

void dfs(int node, int visited[], int V, int adj[V][V], int stack[], int *top)
{
    visited[node] = 1;

    for (int i = 0; i < V; i++)
    {
        if (adj[node][i] && !visited[i])
            dfs(i, visited, V, adj, stack, top);
    }

    stack[(*top)++] = node; // push after DFS (post-order)
}

int main()
{
    int V, E;
    scanf("%d %d", &V, &E);

    int adj[V][V];

    // initialize adjacency matrix
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;

    int u, v;

    // directed edges
    for (int i = 0; i < E; i++)
    {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    int visited[V];
    for (int i = 0; i < V; i++)
        visited[i] = 0;

    int stack[V];
    int top = 0;

    // call DFS for all nodes
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            dfs(i, visited, V, adj, stack, &top);
    }

    // print in reverse order
    for (int i = top - 1; i >= 0; i--)
        printf("%d ", stack[i]);

    return 0;
}
