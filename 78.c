#include <stdio.h>
#include <limits.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int minDist[MAX];

int min(int a, int b) {
    return a < b ? a : b;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    // initialize
    for(int i = 1; i <= n; i++)
    {
        visited[i] = 0;
        minDist[i] = INT_MAX;

        for(int j = 1; j <= n; j++)
            adj[i][j] = INT_MAX;
    }

    int u, v, w;

    // input edges
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w;
    }

    // start from node 1
    minDist[1] = 0;

    int total = 0;

    for(int i = 1; i <= n; i++)
    {
        int u = -1;

        // pick min unvisited
        for(int j = 1; j <= n; j++)
        {
            if(!visited[j] && (u == -1 || minDist[j] < minDist[u]))
                u = j;
        }

        visited[u] = 1;
        total += minDist[u];

        // update neighbors
        for(int v = 1; v <= n; v++)
        {
            if(!visited[v] && adj[u][v] < minDist[v])
            {
                minDist[v] = adj[u][v];
            }
        }
    }

    printf("%d", total);

    return 0;
}
