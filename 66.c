#include <stdio.h>

int dfs(int node, int state[], int V, int adj[V][V])
{
    if (state[node] == 1)
        return 1; // cycle detected

    if (state[node] == 2)
        return 0; // already processed

    state[node] = 1; // mark as visiting

    for (int i = 0; i < V; i++)
    {
        if (adj[node][i])
        {
            if (dfs(i, state, V, adj))
                return 1;
        }
    }

    state[node] = 2; // mark as visited
    return 0;
}

int main()
{
    int V, E;
    scanf("%d %d", &V, &E);

    int adj[V][V];

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;

    int u, v;
    for (int i = 0; i < E; i++)
    {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1; // directed edge
    }

    int state[V];
    for (int i = 0; i < V; i++)
        state[i] = 0;

    for (int i = 0; i < V; i++)
    {
        if (state[i] == 0)
        {
            if (dfs(i, state, V, adj))
            {
                printf("YES");
                return 0;
            }
        }
    }

    printf("NO");
    return 0;
}
